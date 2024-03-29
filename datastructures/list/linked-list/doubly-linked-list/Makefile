# Usage:
# make		# compile and test
# make clean	# remove all objects

.PHONY = all compile test clean

CC = gcc	# define compiler

COMPILERFLAG =  -Wall -Wextra -pedantic -std=c99
LINKERFLAG = -lm

SRCS := $(wildcard *.c)

all: compile test

compile:
	@echo "Compiling"
	${CC} ${SRCS} -o test.o ${COMPILERFLAG} ${LINKERFLAG}

test:
	@echo "Running tests:"
	@./test.o

clean:
	@echo "Cleaning up..."
	rm -rvf *.o

