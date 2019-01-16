
#ifndef UNTITLED19_DATAREADERCLIENT_H
#define UNTITLED19_DATAREADERCLIENT_H
//
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#include "MyTestClientHandler.h"
#include "MatrixSearchable.h"
#include "ServerClientArgs.h"
#include <fstream>

/**
 * class DataReaderClient -  connects to the server
 */
class DataReaderClient {
public:
    static void* ConnectToServer(void * args);
};


#endif //UNTITLED19_DATAREADERCLIENT_H
