#ifndef UNTITLED19_CACHEMANAGER_H
#define UNTITLED19_CACHEMANAGER_H

#include <map>
#include <string>

using namespace std;

/**
 * interface CacheManager - stores the solutions to our problems
 */
class CacheManager {
public:

    /**
     * checks if the Solution Exists
     * @param p string
     * @return bool
     */
    virtual bool SolutionExists(string p) = 0;

    /**
     * Get Solution
     * @param p string
     * @return string
     */
    virtual string GetSolution(string p) = 0;

    /**
     * Add Solution
     * @param p string
     * @param s string
     */
    virtual void AddSolution(string p, string s) = 0;
};


#endif //UNTITLED19_CACHEMANAGER_H
