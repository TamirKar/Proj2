//
// Created by tamir on 1/14/19.
//

#include <fstream>
#include <sstream>
#include "MatrixSearchable.h"

/**
 * MatrixSearchable - constructor
 * @param fileName fileName
 */
MatrixSearchable::MatrixSearchable(const char *fileName) : fileName(fileName) {}
//Initialize the searchable
void MatrixSearchable::InitializeSearchable() {
    //build the graph form the text
    vector<vector<string>> text = ReadText();
    int vertexLocation = 0;
    for (int i = 0; i < text.size() && text[i][0] != "end"; ++i) {
        vector<Vertex> line;
        for (int j = 0; j < text[i].size(); ++j) {
            Vertex vertex(vertexLocation, stoi(text[i][j]));
            line.push_back(vertex);
            vertexLocation++;
        }
        Graph.push_back(line);
    }
    int i = Graph.size()-1;
    this->enterPoint.push_back(Graph[i-1][0].getCost());
    this->enterPoint.push_back(Graph[i-1][1].getCost());
    this->exitPoint.push_back(Graph[i][0].getCost());
    this->exitPoint.push_back(Graph[i][1].getCost());
    this->Graph.resize(Graph.size()-2);
    this->enterLocation = this->enterPoint[1]+this->enterPoint[0]*Graph.size();
    this->exitLocation = this->exitPoint[1]+this->exitPoint[0]*Graph.size();
    this->size=this->Graph.size()*this->Graph[0].size();
    for (int k = 0; k <Graph.size() ; ++k) {
        for (int j = 0; j <Graph[k].size() ; ++j) {
            costs.push_back(Graph[k][j].getCost());
        }

    }
}

/**
 * ReadText - get graph lines from text
 * @return vector<vector<string>>
 */
vector<vector<string>> MatrixSearchable::ReadText() {
    ifstream file(fileName);
    vector<vector<string>> newVec;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> vecLine = RemoveChar(line, ',');
            newVec.push_back(vecLine);
        }
    }
    return newVec;
}

/**
 * RemoveChar - remove a char from a string
 * @param str str
 * @param c c
 * @return vector<string>
 */
vector<string> MatrixSearchable::RemoveChar(string str, char c) {
    vector<string> newVec;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, c)) {
        newVec.push_back(token);
    }
    return newVec;
}

/**
 * GraphToString - convert graph to string form
 * @return string
 */
string MatrixSearchable::GraphToString() {
    string str = "";
    for (int i = 0; i < Graph.size(); ++i) {
        for (int j = 0; j < Graph[i].size(); ++j) {
            str += to_string(Graph[i][j].getCost());
        }
    }
    return str;
}

/**
 * getGraph
 * @return vector<vector<Vertex>>
 */
const vector<vector<Vertex>> &MatrixSearchable::getGraph() const {
    return Graph;
}

/**
 * getEnterPoint
 * @return vector<int>
 */
const vector<int> &MatrixSearchable::getEnterPoint() const {
    return enterPoint;
}

/**
 * getEnterLocation
 * @return int
 */
int MatrixSearchable::getEnterLocation() const {
    return enterLocation;
}

/**
 * getExitPoint
 * @return vector<int>
 */
const vector<int> &MatrixSearchable::getExitPoint() const {
    return exitPoint;
}

/**
 * getSize
 * @return int
 */
int MatrixSearchable::getSize() const {
    return size;
}

/**
 * getCosts
 * @return vector<int>
 */
const vector<int> &MatrixSearchable::getCosts() const {
    return costs;
}

/**
 * getExitLocation
 * @return int
 */
int MatrixSearchable::getExitLocation() const {
    return exitLocation;
}





