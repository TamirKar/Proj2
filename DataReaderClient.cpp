
#include "DataReaderClient.h"

/**
 * connects to the server
 * @param args args
 * @return void *
 */
void *DataReaderClient::ConnectToServer(void *args) {
    //get args for connection
    int port = ((ClientArgs *) args)->port;
    vector<string>  inputStream = ((ClientArgs *) args)->inputStream;
    vector<string>  outputStream = ((ClientArgs *) args)->OutputStream;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    portno = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    bzero(buffer,1024);
    string output;
    //send the input via the buffer
    for(int i=0;i<inputStream.size();i++){
        output=output+inputStream[i]+","+outputStream[i];
        if(i!= inputStream.size() - 1) {
            output = output+",";
        }
    }
    strcpy(buffer,output.c_str());
    //write to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n",buffer);
    return 0;
}
