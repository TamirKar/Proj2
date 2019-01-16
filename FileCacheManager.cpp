
#include "FileCacheManager.h"

/**
 * SolutionExists
 * @param p string
 * @return bool
 */
bool FileCacheManager::SolutionExists(string p) {
    return this->cacheMap.count(p) == 1;
}

/**
 * GetSolution
 * @param p string
 * @return string
 */
string FileCacheManager::GetSolution(string p) {
    return this->cacheMap.at(p);
}

/**
 * AddSolution
 * @param p string
 * @param s string
 */
void FileCacheManager::AddSolution(string p, string s) {
    this->cacheMap.insert(pair<string, string>(p, s));
}
