
#ifndef UNTITLED19_DATAREADERSERVER_H
#define UNTITLED19_DATAREADERSERVER_H
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

/**
 * class DataReaderServer - opens up the server
 */
class DataReaderServer {
public:

    /**
     * OpenServer
     * @param args args
     * @return void*
     */
    static void* OpenServer(void * args);

};


#endif //UNTITLED19_DATAREADERSERVER_H
