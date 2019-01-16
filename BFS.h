#ifndef UNTITLED19_BESTFIRSTSEARCH_H
#define UNTITLED19_BESTFIRSTSEARCH_H


#include "Searchable.h"
#include <vector>
#include <list>
#include "Vertex.h"
#include "Searcher.h"

using namespace std;

/**
 * class of BFS Algorithm
 */
class BFS: public Searcher {

private:
    int cost;
    int numOfNodes;
    vector<vector<Vertex>> Graph;
    int GraphSize;
    list<int> *adjacencyList;
    vector<int>costs;
    int entranceLocation;
    int exitLocation;
    vector<int>path;

public:

    /**
     * constructor
     * @param Graph Graph
     * @param costs costs
     * @param entranceLocation entranceLocation
     * @param exitLocation exitLocation
     */
    BFS(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation,
                    int exitLocation);

    /**
     * add an edge between to Vertexes
     * @param from from
     * @param to to
     */
    void AddEdge(Vertex from,Vertex to);

    /**
     * find the path between two nodes
     */
    void FindPath();

    /**
     * get the nodes in the path
     * @return vector<int>
     */
    const vector<int> &getPath() const;

    /**
     * get the cost of the path
     * @return int
     */
    int getCost() const;

    /**
     * get number of nodes in the path
     * @return int
     */
    int getNumOfNodes() const;

};

#endif //UNTITLED19_BESTFIRSTSEARCH_H
