#include "MySerialServer.h"
#include "MySolver.h"

/**
 * open up the server
 * @param port port
 * @param c c
 */
void MySerialServer::open(int port, ClientHandler *c) {
    //send args via a struct
    ServerArgs *p = new ServerArgs();
    p->c = c;
    p->port = port;
    pthread_t pthread;
    pthread_create(&pthread, nullptr, DataReaderServer::OpenServer, p);
    pthread_detach(pthread);
}

/**
 * close the server
 * @param socket socket
 */
void MySerialServer::stop(int socket) {
    close(socket);
}
