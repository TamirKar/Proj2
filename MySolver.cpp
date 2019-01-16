//
// Created by tamir on 1/15/19.
//

#include <vector>
#include <fstream>
#include <iostream>
#include "MySolver.h"
#include "MatrixSearchable.h"
#include "Vertex.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AStar.h"
#include "ServerClientArgs.h"

/**
 * MySolver - constructor
 * @param cm cm
 */
MySolver::MySolver(CacheManager *cm) : cm(cm) {}

/**
 * solves the problem and returns the best path if exits
 * @param Problem Problem
 * @return string
 */
string MySolver::SolveProblem(string Problem) {
    //get the problems from the user
    vector<string> inputs = getInputs(Problem);
    string solution;
    //solve each problem given
    for (int i = 0; i < inputs.size(); ++i) {
        if (i % 2 != 0) {
            continue;
        }
        //initlize the Graph and get it's properties
        MatrixSearchable *matrixSearchable = new MatrixSearchable(inputs[i].c_str());
        matrixSearchable->InitializeSearchable();
        vector<vector<Vertex>> Graph = matrixSearchable->getGraph();
        vector<int> costs = matrixSearchable->getCosts();
        int enterLocation = matrixSearchable->getEnterLocation();
        int exitLocation = matrixSearchable->getExitLocation();
        vector<int> enterPoint = matrixSearchable->getEnterPoint();
        vector<int> exitPoint = matrixSearchable->getExitPoint();
        string GraphString = matrixSearchable->GraphToString();
        //run the search algorithems to find a path
        DFS *dfs = new DFS(Graph, costs, enterLocation, exitLocation);
        BestFirstSearch *bestfirstsearch = new BestFirstSearch(Graph, costs, enterLocation, exitLocation);
        BFS *bfs = new BFS(Graph, costs, enterLocation, exitLocation);
        Astar *AStar = new Astar(Graph, costs, enterLocation, enterPoint, exitPoint);
        //input Check
        if(Graph.size()!=Graph[0].size()){
            cout<<"Error: Please enter an NxN Matrix"<<endl;
            continue;
        }
        dfs->FindPath();
        bestfirstsearch->FindPath();
        bfs->FindPath();
        AStar->FindPath();
        //get the path lengh from each algorithem
        int dfsPath = dfs->getPath().size();
        int bfsPath = bfs->getPath().size();
        int bestfirstpath = bestfirstsearch->getPath().size();
        int aStarPath = AStar->getPath().size();
        //check which path is the shortest and print it
        if (IsBestPath(dfsPath, bfsPath, aStarPath, bestfirstpath)) {
            PrintBestPath(dfs->getPath(), dfs->getCost(), dfs->getNumOfNodes());

        } else if (IsBestPath(bfsPath, dfsPath, aStarPath, bestfirstpath)) {
            PrintBestPath(bfs->getPath(), bfs->getCost(), bfs->getNumOfNodes());

        } else if (IsBestPath(aStarPath, bfsPath, dfsPath, bestfirstpath)) {
            PrintBestPath(AStar->getPath(), AStar->getCost(), AStar->getNumOfNodes());

        } else if (IsBestPath(bestfirstpath, bfsPath, aStarPath, dfsPath)) {
            PrintBestPath(bestfirstsearch->getPath(), bestfirstsearch->getCost(), bestfirstsearch->getNumOfNodes());

        }
        //get the cost and lengh of each algorithem in a string form
        solution = ToStringSolution(bfs->getCost(), bfs->getNumOfNodes(), dfs->getCost(),
                                    dfs->getNumOfNodes(), bestfirstsearch->getCost(),
                                    bestfirstsearch->getNumOfNodes(), AStar->getCost(), AStar->getNumOfNodes());
        //update the Cache
        this->cm->AddSolution(solution, GraphString);
        ofstream newFile(inputs[i + 1], std::ios_base::app);
        //write them to file
        if (newFile.is_open()) {
            newFile << solution;
        }
        newFile.close();
    }
    return solution;
}

/**
 * convert solution to string
 * @param bfscost bfscost
 * @param bfsNodes bfsNodes
 * @param dfsCost dfsCost
 * @param dfsNodes dfsNodes
 * @param bestfirstCost bestfirstCost
 * @param bestfirstNodes bestfirstNodes
 * @param AStarCost AStarCost
 * @param AstarNodes AstarNodes
 * @return string
 */
string MySolver::ToStringSolution(int bfscost, int bfsNodes, int dfsCost, int dfsNodes, int bestfirstCost,
        int bestfirstNodes, int AStarCost, int AstarNodes) {
    string solution;
    solution = to_string(bestfirstCost) + "," + to_string(bestfirstNodes) + "\n" +
               to_string(dfsCost) + "," + to_string(dfsNodes) + "\n" +
               to_string(bfscost) + "," + to_string(bfsNodes) + "\n" +
               to_string(AStarCost) + "," + to_string(AstarNodes) + "\n";
    return solution;

}

/**
 * get the inputs(problems) from the user
 * @param str str
 * @return vector<string>
 */
vector<string> MySolver::getInputs(string str) {
    if (str[0] == ',') {
        str.erase(0, 1);
    }
    vector<string> inputs;
    int begin = 0;
    int ending = 0;
    while ((ending = str.find(',', begin)) < str.size()) {
        std::string val = str.substr(begin, ending - begin);
        inputs.push_back(val);
        begin = ending + 1;
    }
    if (begin < str.size()) {
        std::string val = str.substr(begin);
        inputs.push_back(val);
    }
    return inputs;
}

/**
 * prints the best path if exists
 * @param path path
 * @param cost cost
 * @param numofnodes numofnodes
 */
void MySolver::PrintBestPath(vector<int> path, int cost, int totalNodes) {
    if(totalNodes==-1||cost==0){
        cout<<"Path Not Found"<<endl;
        return;
    }
    cout<<"Path: ";
    for (int i = 0; i <path.size()-1 ; ++i) {
        if(path[i]-path[i+1]==-1){
            cout<<"Right,";
        } else if(path[i+1]-path[i]==-1){
            cout<<"Left,";

        } else if(path[i]<path[i+1]){
            cout<<"Down,";
        }
        else{
            cout<<"Up,";
        }
    }
    cout<<"\n";
}


/**
 * checks for best path
 * @param size1 size1
 * @param size2 size2
 * @param size3 size3
 * @param size4 size4
 * @return bool
 */
bool MySolver::IsBestPath(int size1, int size2, int size3, int size4) {
    return size1 >= 0 && size1 <= size2 && size1 <= size3 && size1 <= size4;
}

/**
 * MySolver
 * @return CacheManager
 */
CacheManager *MySolver::getcm() {
    return this->cm;
}

/**
 * MySolver
 * @param cm CacheManager
 */
void MySolver::setcm(CacheManager *cm) {
    this->cm = cm;
}






