include ../Make.defines

PROGS = tcpcli01 tcpcli02 tcpserv01

all: ${PROGS}

# %.c:%.o
# 	${CC} ${CFLAGS} $< -o $@ ${LIBS}

tcpcli01: tcpcli01.o strcliselect01.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

tcpcli02:tcpcli01.o strcliselect02.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

tcpserv01:tcpservselect.o
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

.PHONY: clear

clear: 
	@rm -f ${PROGS} ${CLEARFILES}
