#include <iostream>
#include "DFS.h"
#include "MatrixSearchable.h"

/**
 * constructor
 * @param Graph Graph
 * @param costs costs
 * @param entranceLocation entranceLocation
 * @param exitLocation exitLocation
 */
DFS::DFS(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation, int exitLocation) : Graph(
        Graph), costs(costs), entranceLocation(entranceLocation), exitLocation(exitLocation) {
    this->GraphSize = this->Graph.size() * this->Graph[0].size();
    this->adjacencyList = new list<int>[this->GraphSize];
    numOfNodes=-1;
    cost=0;
    //add edges to graph
    for (int i = 0; i < Graph.size(); i++) {
        for (int j = 0; j < Graph[i].size(); j++) {
            if (Graph[i][j].getCost() == -1) {
                continue;
            }
            if (i != 0) {
                AddEdge(Graph[i][j], Graph[i - 1][j]);
            }
            if (i != Graph.size() - 1) {
                AddEdge(Graph[i][j], Graph[i + 1][j]);
            }
            if (j != 0) {
                AddEdge(Graph[i][j], Graph[i][j - 1]);
            }
            if (j != Graph.size() - 1) {
                AddEdge(Graph[i][j], Graph[i][j + 1]);
            }
        }
    }
}

/**
 * add edge to graph
 * @param from from
 * @param to to
 */
void DFS::AddEdge(Vertex from, Vertex to) {
    this->adjacencyList[from.getLocation()].push_back(to.getLocation());
}

/**
 * find the path between two nodes
 */
void DFS::FindPath() {
    bool *visited = new bool[GraphSize];
    for (int i = 0; i < GraphSize; i++){
        visited[i] = false;
    }
    DFSUtil(this->entranceLocation,this->exitLocation,visited);
}

/**
 * Traverse recursively until target node is found
 * @param from from
 * @param to to
 * @param visited visited
 */
void DFS::DFSUtil(int from, int to, bool *visited) {
    visited[from] = true;
    cost += costs[from];
    path.push_back(from);
    numOfNodes++;
    if(from == to) {
        PathFound= true;
        cost-=costs[entranceLocation];
        return;
    }
    list<int>::iterator i;
    for (i = adjacencyList[from].begin(); i != adjacencyList[from].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, to,visited);
        }
        if(PathFound){
            return;
        }
    }
}

/**
 * getPath
 * @return vector<int>
 */
const vector<int> &DFS::getPath() const {
    return path;
}

/**
 * getCost
 * @return int
 */
int DFS::getCost() const {
    return cost;
}

/**
 * getNumOfNodes
 * @return int
 */
int DFS::getNumOfNodes() const {
    return numOfNodes;
}





