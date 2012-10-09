SRC=$(wildcard *.c)
OBJ=$(SRC:.cpp=.o)

FLAGS = -Wall -c
FLEXE = -Wall -o

all:pgm

pgm:$(OBJ)
	gcc $^ $(FLEXE) test
	
%.o:%.cpp
	gcc $(FLAGS) $<
	
clean :
	rm -f *.o pgm
