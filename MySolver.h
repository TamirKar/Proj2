//
// Created by tamir on 1/15/19.
//

#ifndef UNTITLED19_MYSOLVER_H
#define UNTITLED19_MYSOLVER_H

#include "Solver.h"
#include "FileCacheManager.h"

/**
 * class of MySolver - Solve the shortest path problem
 * and finds if a path exists.
 * if it exists the solver checks for the best path between
 * the search algorithms and gives it to the user.
 */
class MySolver : public Solver {
public:

    /**
     * constructor
     * @param cm CacheManager
     */
    MySolver(CacheManager *cm);

    /**
     * solves the problem and returns the best path if exits
     * @param Problem Problem
     * @return string
     */
    string SolveProblem(string Problem) override;

    /**
     * get the problems from the user
     * @param str str
     * @return vector<string>
     */
    vector<string> getInputs(string str);

    /**
     * convert solution to string
     * @param bfsCost bfsCost
     * @param bfsNodes bfsNodes
     * @param dfsCost dfsCost
     * @param dfsNodes dfsNodes
     * @param bestfirstCost bestfirstCost
     * @param bestfirstNodes bestfirstNodes
     * @param AStarCost AStarCost
     * @param AstarNodes AstarNodes
     * @return string
     */
    string ToStringSolution(int bfsCost, int bfsNodes, int dfsCost, int dfsNodes, int bestfirstCost, int bestfirstNodes,
                            int AStarCost, int AstarNodes);

    /**
     * setter for cm to save the solution
     * @return CacheManager
     */
    CacheManager *getcm() override;

    /**
     * getter for cm to save the solution
     * @param cm CacheManager
     */
    void setcm(CacheManager *cm) override;

    /**
     * prints the best path if exists
     * @param path path
     * @param cost cost
     * @param totalNodes totalNodes
     */

    /**
     * checks for best path
     * @param size1 size1
     * @param size2 size2
     * @param size3 size3
     * @param size4 size4
     * @return bool
     */
    bool IsBestPath(int size1, int size2, int size3, int size4);

    void PrintBestPath(vector<int> path, int cost, int totalNodes);

private:
    CacheManager *cm;
};

#endif //UNTITLED19_MYSOLVER_H
