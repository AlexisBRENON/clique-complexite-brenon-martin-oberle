SRC=$(wildcard *.c)
OBJ=$(SRC:.cpp=.o)

CFLAGS = -g


all:$(OBJ)
	gcc $^ -o test

%.o:%.cpp
	gcc $(CFLAGS) $<

clean :
	rm -f *.o
