

#ifndef UNTITLED19_MYTESTCLIENTHANDLER_H
#define UNTITLED19_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "FileCacheManager.h"

/**
 * MyTestClientHandler - handles the clients that connect to the server
 */
class MyTestClientHandler : public ClientHandler {
public:

    /**
     * MyTestClientHandler - constructor
     * @param portConnect portConnect
     */
    MyTestClientHandler(int portConnect) {
        this->portConnect = portConnect;
        this->cacheManager = new FileCacheManager();
    }

    /**
     * get the problems given from the client and handles them
     * @param inputStream inputStream
     * @param outputStream outputStream
     */
    void HandleClient(vector<string> inputStream, vector<string> outputStream) override;

    /**
     * getcm
     * @return CacheManager
     */
    CacheManager *getcm() override;

    /**
     * setcm
     * @param cm cm
     */
    void setcm(CacheManager *cm) override;

    /**
     * GetSolver
     * @return Solver
     */
    Solver *GetSolver() override;

    /**
     * SetSolver
     * @param solver solver
     */
    void SetSolver(Solver *solver) override;

private:
    int portConnect;
    Solver *solver;
    CacheManager *cacheManager;
};

#endif //UNTITLED19_MYTESTCLIENTHANDLER_H

