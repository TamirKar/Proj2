#include <iostream>
#include "MatrixSearchable.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AStar.h"
#include "MyTestClientHandler.h"
#include "Server.h"
#include <vector>
#include <string>
#include "MySerialServer.h"

using namespace std;

int main(int argc, char **argv) {
    //set up the server
    server_side::Server *server = new MySerialServer();
    int port = stoi(argv[1]);
    //set the client handler
    MyTestClientHandler *ch = new MyTestClientHandler(port);
    //open up the server
    server->open(port, ch);
    //get inputs from textiles
    vector<string> inputStream;
    vector<string> outputStream;
    inputStream.push_back("Z1.txt");
    inputStream.push_back("Z2.txt");
    inputStream.push_back("Z3.txt");
    inputStream.push_back("Z4.txt");
    inputStream.push_back("Z5.txt");
    inputStream.push_back("Z6.txt");
    inputStream.push_back("Z7.txt");
    inputStream.push_back("Z8.txt");
    inputStream.push_back("Z9.txt");
    inputStream.push_back("Z10.txt");
    //get outputs location
    for (int i = 0; i <10 ; ++i) {
        outputStream.push_back("solution.txt");
    }
    //connect to the server and handle the clients via the client handler.
    ch->HandleClient(inputStream, outputStream);
}