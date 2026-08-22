CC = gcc

all:
	$(CC) main.c preprocessor.c -o my_Preprocessor

run:
	./my_Preprocessor abc.c

clean:
	rm -f my_Preprocessor abc.i
