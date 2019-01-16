
#ifndef UNTITLED19_SEARCHER_H
#define UNTITLED19_SEARCHER_H

#include "Vertex.h"
#include <vector>

using namespace std;


/**
 * Searcher - to solve the problem
 */
class Searcher {

    /**
     * find a path between two nodes in a graph
     */
    virtual void FindPath() = 0;
};

#endif //UNTITLED19_SEARCHER_H
