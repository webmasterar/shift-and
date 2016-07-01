ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT =
	endif
endif

CC = gcc
CFLAGS = -msse4.2 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: shift-and
	$(CC) $(CFLAGS) -o shift-and$(EXT) shift-and.o main.o

shift-and:
	$(CC) $(CFLAGS) -c shift-and.c main.c

clean:
	$(RM) shift-and.o main.o shift-and$(EXT)
