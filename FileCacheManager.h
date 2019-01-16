
#ifndef UNTITLED19_FILECACHEMANAGER_H
#define UNTITLED19_FILECACHEMANAGER_H

#include "CacheManager.h"

/**
 * class FileCacheManager - stores the solutions to our problems
 */
class FileCacheManager : public CacheManager  {
private:
    map<string ,string> cacheMap;

public:

    /**
     * SolutionExists
     * @param p string
     * @return bool
     */
    bool SolutionExists(string p) override;

    /**
     * GetSolution
     * @param p string
     * @return string
     */
    string GetSolution(string p) override;

    /**
     * AddSolution
     * @param p string
     * @param s string
     */
    void AddSolution(string p, string s) override;
};

#endif //UNTITLED19_FILECACHEMANAGER_H
