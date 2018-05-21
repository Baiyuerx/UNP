include ../Make.defines

PROGS = tcpcli02 tcpserv02

all : ${PROGS}

tcpcli02:tcpcli02.o 
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

tcpserv02:tcpserv02.o str_echo_stdio02.o sigchildwaitpid.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

.PHONY:clear clean

clear:
	@rm -f ${CLEARFILES}

clean:
	@rm -f ${PROGS}
