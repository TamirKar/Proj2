//
// Created by tamir on 1/14/19.
//

#ifndef UNTITLED19_DFS_H
#define UNTITLED19_DFS_H

#include "Vertex.h"
#include "Searcher.h"
#include <vector>
#include <list>

using namespace std;

/**
 * class of DFS Algorithm
 */
class DFS : public Searcher {
private:
    vector<vector<Vertex>> Graph;
    int GraphSize;
    list<int> *adjacencyList;
    vector<int> costs;
    int entranceLocation;
    int exitLocation;
    bool PathFound = false;
    vector<int> path;
    int cost;
    int numOfNodes;
public:

    /**
     * constructor
     * @param Graph Graph
     * @param costs costs
     * @param entranceLocation entranceLocation
     * @param exitLocation exitLocation
     */
    DFS(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation, int exitLocation);

    /**
     * add an edge to graph
     * @param from from
     * @param to to
     */
    void AddEdge(Vertex from, Vertex to);

    /**
     * find a path between nodes in the graph
     */
    void FindPath() override;

    /**
     * Traverse recursively until target node is found
     * @param from from
     * @param to to
     * @param visited visited
     */
    void DFSUtil(int from, int to, bool visited[]);

    /**
     * getPath
     * @return vector<int>
     */
    const vector<int> &getPath() const;

    /**
     * getCost
     * @return int
     */
    int getCost() const;

    /**
     * getNumOfNodes
     * @return int
     */
    int getNumOfNodes() const;

};

#endif //UNTITLED19_DFS_H
