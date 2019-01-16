#include <iostream>
#include "BFS.h"
#include <algorithm>

// std::reverse
/**
 * constructor
 * @param Graph Graph
 * @param costs costs
 * @param entranceLocation entranceLocation
 * @param exitLocation exitLocation
 */
BFS::BFS(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation,
                                 int exitLocation) : Graph(Graph), costs(costs), entranceLocation(entranceLocation),
                                                     exitLocation(exitLocation) {
    this->GraphSize = this->Graph.size() * this->Graph[0].size();
    this->adjacencyList = new list<int>[this->GraphSize];
    numOfNodes=-1;
    cost = 0;
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
 * add an edge to the graph
 * @param from from
 * @param to to
 */
void BFS::AddEdge(Vertex from, Vertex to) {
    this->adjacencyList[from.getLocation()].push_back(to.getLocation());
}

/**
 * find a path between to nodes in the graph
 */
void BFS::FindPath() {
    bool *visited = new bool[GraphSize];
    //mark as not visited
    for (int i = 0; i < GraphSize; i++) {
        visited[i] = false;
    }
    list<int> queue;
    visited[this->entranceLocation] = true;
    queue.push_back(this->entranceLocation);
    list<int>::iterator i;
    //dequeue
    while (!queue.empty()) {
        int v = queue.front();
        path.push_back(v);
        cost += costs[v];
        this->numOfNodes++;
        queue.pop_front();
        //go over the  adjacencyList for possible path
        for (i = adjacencyList[v].begin(); i != adjacencyList[v].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cost-=costs[entranceLocation];
}

/**
 * getters
 * @return int
 */
int BFS::getCost() const {
    return cost;
}

/**
 * getNumOfNodes
 * @return int
 */
int BFS::getNumOfNodes() const {
    return numOfNodes;
}

/**
 * getPath
 * @return vector<int>
 */
const vector<int> &BFS::getPath() const {
    return path;
}



