//
// Created by tamir on 1/14/19.
//

#ifndef UNTITLED19_MATRIXSEARCHABLE_H
#define UNTITLED19_MATRIXSEARCHABLE_H

#include "Vertex.h"
#include <vector>
#include <string>
#include "Searchable.h"

using namespace std;

/**
 * MatrixSearchable
 */
class MatrixSearchable : public Searchable {
private:
    const char *fileName;
    vector<vector<Vertex>> Graph;
    vector<int> costs;
    vector<int> enterPoint;
    int enterLocation;
    vector<int> exitPoint;
    int size;
    int exitLocation;
public:

    /**
     * constructor
     * @param fileName fileName
     */
    MatrixSearchable(const char *fileName);

    /**
     * Initialize the searchable
     */
    void InitializeSearchable() override;

    /**
     * convert graph to string form
     * @return string
     */
    string GraphToString();

    /**
     * get graph lines from text
     * @return <vector<string>>
     */
    vector<vector<string>> ReadText();

    /**
     * remove a char from a string
     * @return vector<string>
     */
    vector<string> RemoveChar(string, char);

    /**
     * getEnterLocation
     * @return int
     */
    int getEnterLocation() const;

    /**
     * getCosts
     * @return vector<int>
     */
    const vector<int> &getCosts() const;

    /**
     * getEnterPoint
     * @return vector<int>
     */
    const vector<int> &getEnterPoint() const;

    /**
     * getExitPoint
     * @return  vector<int>
     */
    const vector<int> &getExitPoint() const;

    /**
     * getSize
     * @return int
     */
    int getSize() const;

    /**
     * getExitLocation
     * @return int
     */
    int getExitLocation() const;

    /**
     * getGraph
     * @return vector<vector<Vertex>>
     */
    const vector<vector<Vertex>> &getGraph() const;
};

#endif //UNTITLED19_MATRIXSEARCHABLE_H
