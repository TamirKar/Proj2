//
// Created by tamir on 1/15/19.
//

#ifndef UNTITLED19_GLOBALS_H
#define UNTITLED19_GLOBALS_H

#include "ClientHandler.h"
#include "CacheManager.h"

/**
 * store the server and client's args in a struct to pass function in thread
 */
struct ServerArgs {
    int port;
    ClientHandler* c;
};

struct ClientArgs {
    vector<string> inputStream;
    vector<string> OutputStream;
    int port;
};

#endif //UNTITLED19_GLOBALS_H
