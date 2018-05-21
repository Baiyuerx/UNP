include ../Make.defines

PROGS = udpserv01 udpcli01 udpcli02

all: ${PROGS}

udpcli01:udpcli01.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

udpserv01:udpserv01.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

udpcli02:udpcli01.o dgcliconnect.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

.PHONY: clean clear

clear:
	@rm -f ${CLEARFILES}

clean: 
	@rm -f ${PROGS}
