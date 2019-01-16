
#ifndef UNTITLED19_SERVER_H
#define UNTITLED19_SERVER_H

#include "ClientHandler.h"

namespace server_side {

    /**
     * opens or stops the server
     */
    class Server {
    public:

        /**
         * open
         * @param port port
         * @param c c
         */
        virtual void open(int port, ClientHandler *c) = 0;

        /**
         * stop
         * @param sockfd sockfd
         */
        virtual void stop(int sockfd) = 0;
    };
}

#endif //UNTITLED19_SERVER_H
