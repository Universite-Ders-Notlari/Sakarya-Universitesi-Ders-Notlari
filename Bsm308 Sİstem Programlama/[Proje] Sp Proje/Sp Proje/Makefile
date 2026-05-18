
INCLUDE = -I ./include
LIBDIR = ./objs
CC = gcc
LIBS = $(LIBDIR)/libfdr.a
CFLAGS = -g $(INCLUDE)
ALL = odev

all: $(ALL)

clean:
	rm -f *.o core $(ALL)

odev: 
	$(CC) $(CFLAGS) -o program.o ./src/main.c $(LIBS)


