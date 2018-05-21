include ../Make.defines

PROGS= hostent

all: ${PROGS}

hostent: hostent.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

.PHONY:clear clean

clear:
	@rm -f ${CLEARFILES}

clean:
	@rm -f ${PROGS}

