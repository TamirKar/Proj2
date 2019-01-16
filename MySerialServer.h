//
// Created by tamir on 1/15/19.
//

#ifndef UNTITLED19_MYSERIALSERVER_H
#define UNTITLED19_MYSERIALSERVER_H


#include <iostream>
#include "Server.h"
#include <pthread.h>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "MySolver.h"
#include <netdb.h>
#include "ServerClientArgs.h"
#include "DataReaderServer.h"

/**
 * class of MySerialServer - handles the client one after the other.
 */
class MySerialServer: public server_side::Server{
public:

    /**
     * open up the server
     * @param port port
     * @param c c
     */
    void open(int port, ClientHandler *c);

    /**
     * close the server
     * @param socket socket
     */
    void stop(int socket) override;
};

#endif //UNTITLED19_MYSERIALSERVER_H
