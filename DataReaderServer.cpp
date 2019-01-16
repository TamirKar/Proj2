

#include <netinet/in.h>
#include "DataReaderServer.h"
#include "ServerClientArgs.h"
#include "MyTestClientHandler.h"


/**
 * opens up the server
 * @param args args
 * @return void *
 */
void *DataReaderServer::OpenServer(void *args) {
    //get args of server
    int port = ((ServerArgs *) args)->port;
    ClientHandler* c = ((ServerArgs *) args)->c;
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    bzero(buffer,1024);
    n = read( newsockfd,buffer,1023 );
    //use solver to solve the problem
    c->SetSolver(new MySolver(c->getcm()));
    c->GetSolver()->SolveProblem(buffer);
    c->setcm(c->GetSolver()->getcm());
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    exit(0);
}
