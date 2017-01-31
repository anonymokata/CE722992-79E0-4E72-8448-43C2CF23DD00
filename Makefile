
#CFLAGS := `pkg-config --cflags --libs check`
CFLAGS := -pthread -lcheck_pic -pthread -lrt -lm

roman:main.o roman.o
	gcc $^ -o $@ $(CFLAGS)

%.o:%.cpp
	gcc -c $< -o $@ $(CFLAGS)

clean:
	rm -f roman *.o

