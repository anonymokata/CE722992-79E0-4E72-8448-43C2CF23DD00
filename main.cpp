#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "roman.h"

START_TEST(test_romanAdd)
{
    const char *a = NULL;
    const char *b = NULL;
    const char *c = NULL;

    a = "XIV";
    b = "LX";
    c = "LXXIV";
    ck_assert_str_eq(Addition(a,b), c);

    a = "XX";
    b = "II";
    c = "XXII";
    ck_assert_str_eq(Addition(a,b), c);

    a = "II";
    b = "II";
    c = "IV";
    ck_assert_str_eq(Addition(a,b), c);

    a = "D";
    b = "D";
    c = "M";
    ck_assert_str_eq(Addition(a,b), c);
}
END_TEST


START_TEST(test_romanMinus)
{
    const char *a = NULL;
    const char *b = NULL;
    const char *c = NULL;
    char *ret;

    a = "XIV";
    b = "LX";
    c = "LXXIV";

    ret = Subtraction(a,b);
    if(ret!=NULL)
    {
        //printf("%s - %s = %s(res=%s)\n", a, b, c, ret);
        ck_assert_str_eq(Subtraction(a,b), c);
    }

    a = "LXXIV";
    b = "LX";
    c = "XIV";
    ret = Subtraction(a,b);
    if(ret!=NULL)
    {
        //printf("%s - %s = %s(res=%s)\n", a, b, c, ret);
        ck_assert_str_eq(Subtraction(a,b), c);
    }

}
END_TEST

Suite* suite_roman(void)
{
    Suite *s;
    TCase* tc;

    s = suite_create("suite_roman");

    // Addition
    tc = tcase_create("romanAdd");
    tcase_add_test(tc, test_romanAdd);
    suite_add_tcase(s, tc);
    
    // Subtraction
    tc = tcase_create("romanMinus");
    tcase_add_test(tc, test_romanMinus);
    suite_add_tcase(s, tc);


    return s;
}

int main(int argc, char* argv[])
{
    int number_failed;

    SRunner *sr;

    Suite* s_roman = suite_roman();

    sr = srunner_create(s_roman);


    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (number_failed==0)?EXIT_SUCCESS:EXIT_FAILURE;
}

