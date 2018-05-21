INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

SET(SRC_CLI01 tcpcli01.c strclithread.c)
SET(SRC_SERV01 tcpserv01.c)

add_executable(tcpcli01 ${SRC_CLI01})
add_executable(tcpserv01 ${SRC_SERV01})

target_link_libraries(tcpcli01 ${PROJECT_SOURCE_DIR}/libunp.a)
target_link_libraries(tcpserv01 ${PROJECT_SOURCE_DIR}/libunp.a)