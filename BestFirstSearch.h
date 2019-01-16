
#ifndef UNTITLED19_BFS_H
#define UNTITLED19_BFS_H


#include "Vertex.h"
#include "Searcher.h"
#include <vector>
#include <list>

using namespace std;

/**
 * class of BestFirstSearch Algorithm
 */
class BestFirstSearch :public Searcher{
private:
    int cost;
    int numOfNodes;
    vector<vector<Vertex>> Graph;
    int GraphSize;
    vector<int> *adjacencyList;
    vector<int>costs;
    vector<int>saveLocations;
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
    BestFirstSearch(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation, int exitLocation);

    /**
     * add an edge between to Vertexes
     * @param from from
     * @param to to
     */
    void AddEdge(Vertex from,Vertex to);

    /**
     * find the path between two nodes
     */
    void FindPath() override;

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

    /**
     * get the nodes in the path
     * @return  vector<int>
     */
    const vector<int> &getPath() const;

};


#endif //UNTITLED19_BFS_H
