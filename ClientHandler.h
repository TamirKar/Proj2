#ifndef UNTITLED19_CLIENTHANDLER_H
#define UNTITLED19_CLIENTHANDLER_H

#include <vector>
#include <string>
#include <map>
#include "CacheManager.h"
#include "MySolver.h"

using namespace std;

/**
 * ClientHandler
 */
class ClientHandler {
public:

    /**
     * HandleClient
     * @param inputStream inputStream
     * @param outputStream outputStream
     */
    virtual void HandleClient(vector<string> inputStream, vector<string> outputStream) = 0;

    /**
     * getcm
     * @return CacheManager
     */
    virtual CacheManager *getcm() = 0;

    /**
     * setcm
     * @param cm CacheManager
     */
    virtual void setcm(CacheManager *cm) = 0;

    /**
     * GetSolver
     * @return Solver
     */
    virtual Solver *GetSolver() = 0;

    /**
     * SetSolver
     * @param solver solver
     */
    virtual void SetSolver(Solver *solver) = 0;

};

#endif //UNTITLED19_CLIENTHANDLER_H
