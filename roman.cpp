#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
	E_M  = 1000, //'M',
	E_CM = 900,  //////// CM
	E_D  = 500,  //'D',
	E_CD = 400,  //////// CD
	E_C  = 100,  //'C',
	E_XC = 90,   //////// XC
	E_L  = 50,   //'L',
	E_XL = 40,   //////// XL
	E_X  = 10,   //'X',
	E_IX = 9,    //////// IX,
	E_V  = 5,    //'V',
	E_IV = 4,    //////// IV
	E_I  = 1,    //'I',
};

static int romanMap(char c)
{
	switch (c)
	{
		case 'I':
			return E_I;
		case 'V':
			return E_V;
		case 'X':
			return E_X;
		case 'L':
			return E_L;
		case 'C':
			return E_C;
		case 'D':
			return E_D;
		case 'M':
			return E_M;
		default:
			return -1;
	}
}

static int romanToInt(const char* s) {
	//const static int map[] = {};
	int len = strlen(s);
	int prev = 0;
	int total = 0;
	for (int i = 0; i < len; i++)
	{
		int cur = romanMap(s[i]);
		total += (cur > prev) ? (cur - 2 * prev) : cur;
		prev = cur;
	}

	return total;
}

static int getDivider(int i)
{
	switch (i)
	{
		case 0:
			return E_M;	 // E_M  = 1000, //'M',
		case 1:
			return E_CM; // = 900,  //////// CM;
		case 2:
			return E_D;  // = 500,  //'D',;
		case 3:
			return E_CD; // = 400,  //////// CD;
		case 4:
			return E_C;  // = 100,  //'C',;
		case 5:
			return E_XC; // = 90,   //////// XC;
		case 6:
			return E_L;  // = 50,   //'L',
		case 7:
			return E_XL; // = 40,   //////// XL;
		case 8:
			return E_X;  // = 10,   //'X',;
		case 9:
			return E_IX; // = 9,    //////// IX,;
		case 10:
			return E_V;  // = 5,    //'V',;
		case 11:
			return E_IV; // = 4,    //////// IV
		case 12:
			return E_I;  // = 1,    //'I',
		default:
			return -1;
	}
}

static const char* getSyms(int i)
{
	switch (i)
	{
		case 0:
			return "M";	 // E_M  = 1000, //'M',
		case 1:
			return "CM"; // = 900,  //////// CM;
		case 2:
			return "D";  // = 500,  //'D',;
		case 3:
			return "CD"; // = 400,  //////// CD;
		case 4:
			return "C";  // = 100,  //'C',;
		case 5:
			return "XC"; // = 90,   //////// XC;
		case 6:
			return "L";  // = 50,   //'L',
		case 7:
			return "XL"; // = 40,   //////// XL;
		case 8:
			return "X";  // = 10,   //'X',;
		case 9:
			return "IX"; // = 9,    //////// IX,;
		case 10:
			return "V";  // = 5,    //'V',;
		case 11:
			return "IV"; // = 4,    //////// IV
		case 12:
			return "I";  // = 1,    //'I',
		default:
			return NULL;
	}
}

static char* intToRoman(int num) {
	char *str = NULL;
	char *cur = NULL;
	int i = 0;
	int divider = -1;

	while (num > 0)
	{
		divider = getDivider(i);
		if (divider == -1) return NULL;

		int k = num/divider;

		for (int j = 0; j < k; j++)
		{
			const char *val = getSyms(i);
			if (val == NULL) return NULL;

			if (str == NULL)
			{
				str = (char *)malloc(strlen(val) + 1);
				memset(str, 0, strlen(val)+1);
			}
			else
			{
				str = (char *)realloc(str, strlen(str) + strlen(val) + 1);
			}

			strncat(str, val, strlen(val));

			num -= divider;
		}
		i++;
	}

	return str;
}

char *Addition(const char *a, const char *b)
//char *romanAdd(const char *a, const char *b)
{
	int aa = romanToInt(a);
	int bb = romanToInt(b);

	int cc = aa + bb;

	return intToRoman(cc);

}

char *Subtraction(const char *a, const char *b)
//char *romanMinus(char *a, char *b)
{
    int aa = romanToInt(a);
    int bb = romanToInt(b);

    int cc = aa - bb;

    if(cc<=0)
    {
        return NULL;
    }

    return intToRoman(cc);
}

