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
#include "DataReaderClient.h"

/**
 * get the problems given from the client
 * and save the solution to a fail
 * @param inputStream
 * @param outputStream
 */
void MyTestClientHandler::HandleClient(vector<string> inputStream, vector<string> outputStream) {
    for(int i=0;i<inputStream.size();i++){
        //create a searchable graph for the problem
        MatrixSearchable * matrixSearchable = new MatrixSearchable(inputStream[i].c_str());
        matrixSearchable->InitializeSearchable();
        string strGraph = matrixSearchable->GraphToString();
        //check if a solution already exists in the cache
        if (this->cacheManager->SolutionExists(strGraph)) {
            //if it is write it to the file
            ofstream file(outputStream[i], std::ios_base::app);
            inputStream.erase(inputStream.begin() + i);
            outputStream.erase(outputStream.begin() + i);
            if (file.is_open()) {
                file << this->cacheManager->GetSolution(strGraph) << "\n";
            } else {
                perror("Error opening file.");
            }
            file.close();
        }
        //connect to the server the problem will be solved in the server by the solver
        ClientArgs *p = new ClientArgs();
        p->port=portConnect;
        p->inputStream=inputStream;
        p->OutputStream=outputStream;
        pthread_t pthread;
        pthread_create(&pthread, nullptr, DataReaderClient::ConnectToServer, p);
        pthread_join(pthread, nullptr);
    }
}

/**
 * MyTestClientHandler
 * @return CacheManager
 */
CacheManager *MyTestClientHandler::getcm() {
    return this->cacheManager;
}

/**
 * setcm
 * @param cm CacheManager
 */
void MyTestClientHandler::setcm(CacheManager * cm) {
    this->cacheManager= cm;
}

/**
 * SetSolver
 * @param solver solver
 */
void MyTestClientHandler::SetSolver(Solver *solver) {
    this->solver=solver;

}

/**
 * GetSolver
 * @return Solver
 */
Solver *MyTestClientHandler::GetSolver() {
    return this->solver;
}








