CFLAGS=-Wall -O2
src=$(wildcard *.c)
#prg=$(patsubst %.c, %, $(src))
prg=$(src:%.c=%)

all: $(prg)

clean:
	rm $(prg)
