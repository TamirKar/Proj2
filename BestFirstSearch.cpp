#include <iostream>
#include "BestFirstSearch.h"

/**
 * constructor
 * @param Graph Graph
 * @param costs costs
 * @param entranceLocation entranceLocation
 * @param exitLocation exitLocation
 */
BestFirstSearch::BestFirstSearch(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation,
                                 int exitLocation) : Graph(
        Graph), costs(costs), entranceLocation(entranceLocation), exitLocation(exitLocation) {
    this->GraphSize = this->Graph.size() * this->Graph[0].size();
    adjacencyList = new vector<int>[GraphSize];
    vector<int> saveLocations(this->GraphSize);
    this->saveLocations = saveLocations;
    //save the location of the vertexes
    this->saveLocations[this->entranceLocation] = -1;
    numOfNodes = -1;
    cost = 0;
    //add edges to the graph
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
void BestFirstSearch::AddEdge(Vertex from, Vertex to) {
    this->adjacencyList[from.getLocation()].push_back(to.getLocation());

}

/**
 * find a path between to vertexes in the graph
 */
void BestFirstSearch::FindPath() {
    bool *visited = new bool[this->GraphSize];
    if (this->entranceLocation == this->exitLocation) {
        cout << entranceLocation << endl;
        return;
    }
    //mark nodes as not visited
    for (int i = 0; i < this->GraphSize; ++i) {
        visited[i] = false;
    }
    list<int> queue;
    visited[this->entranceLocation] = true;
    queue.push_back(this->entranceLocation);
    vector<int>::iterator i;
    while (!queue.empty()) {
        int s = queue.front();
        queue.pop_front();
        //look for target node on the adjacency List mark nodes that are visited
        for (i = adjacencyList[s].begin(); i != adjacencyList[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                //save nodes that are visited
                saveLocations[*i] = s;
                //if target node is found there is a path
                if (*i == exitLocation) {
                    int location = *i;
                    //get the previous nodes we saved
                    while (location != -1) {
                        numOfNodes++;
                        cost += costs[location];
                        path.push_back(location);
                        location = saveLocations[location];
                    }
                    //remove cost of first node
                    cost -= costs[entranceLocation];
                } else {
                    queue.push_back(*i);
                }
            }
        }
    }
}

/**
 * getters
 * @return vector<int>
 */
const vector<int> &BestFirstSearch::getPath() const {
    return path;
}

/**
 * getCost
 * @return int
 */
int BestFirstSearch::getCost() const {
    return cost;
}

/**
 * getNumOfNodes
 * @return int
 */
int BestFirstSearch::getNumOfNodes() const {
    return numOfNodes;
}



