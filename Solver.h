#ifndef UNTITLED19_SOLVER_H
#define UNTITLED19_SOLVER_H

#include <string>
#include "CacheManager.h"
#include <vector>
using namespace std;

/**
 * solve the problem
 */
class Solver {
public:

    /**
     * SolveProblem
     * @param Problem Problem
     * @return string
     */
    virtual string SolveProblem(string Problem) = 0;

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
};

#endif //UNTITLED19_SOLVER_H
