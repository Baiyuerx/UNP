include ../Make.defines

PROGS  = tcpcli01 tcpserv01  tcpserv02 tcpcli02 tcpcli03 tcpserv03


all:${PROGS}

%.c:%.o
	${CC} -c $< -o $@

tcpcli01:tcpcli01.o
	${CC} ${CFLAGS} $< -o $@ ${LIBS}

tcpcli02:tcpcli02.o
	${CC} ${CFLAGS} $< -o $@ ${LIBS}

tcpserv01:tcpserv01.o
	${CC} ${CFLAGS} $< -o $@ ${LIBS}

tcpserv02:tcpserv02.o sigchildwait.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS} 

tcpserv03:tcpserv03.o sigchildwaitpid.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}


.PHONY:clean

clean:
	@rm -f ${PROGS} ${OBJS} ${CLEARFILES}
