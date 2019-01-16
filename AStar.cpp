
#include "AStar.h"
#include <math.h>
#include<iostream>

using namespace std;

/**
 * the function calculates the graph
 * @param temp_start temp_start
 * @param point point
 * @return int
 */
int Astar::calcG(Point *temp_start, Point *point) {
    int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
    int parentG = point->parent == NULL ? 0 : point->parent->G;
    return parentG + extraG;
}

/**
 * the function calculates the heuristic
 * @param point point
 * @param end end
 * @return int
 */
int Astar::calcH(Point *point, Point *end) {
    return sqrt((double) (end->x - point->x) * (double) (end->x - point->x) +
                (double) (end->y - point->y) * (double) (end->y - point->y)) * kCost1;
}

/**
 * unites the graph and the heuristic
 * @param point point
 * @return int
 */
int Astar::calcF(Point *point) {
    return point->G + point->H;
}

/**
 * reurns the result point from the list
 * @return rusult point
 */
Point *Astar::getLeastFpoint() {
    if (!openList.empty()) {
        auto resPoint = openList.front();
        for (auto &point : openList)
            if (point->F < resPoint->F)
                resPoint = point;
        return resPoint;
    }
    return NULL;
}

/**
 * get the path
 * @param startPoint startPoint
 * @param endPoint endPoint
 * @param isIgnoreCorner isIgnoreCorner
 * @return point
 */
Point *Astar::getPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner) {
    // open list and put inside the points
    openList.push_back(new Point(startPoint.x, startPoint.y));
    while (!openList.empty()) {
        auto curPoint = getLeastFpoint();
        openList.remove(curPoint);
        closeList.push_back(curPoint);
        auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);

        // for each one of the adjacent vertex
        for (auto &target : surroundPoints) {
            // if it is in the list
            if (!isInList(openList, target)) {
                target->parent = curPoint;
                target->G = calcG(curPoint, target);
                target->H = calcH(target, &endPoint);
                target->F = calcF(target);
                openList.push_back(target);
            }

                // if they are not in the list
            else {
                int tempG = calcG(curPoint, target);
                if (tempG < target->G) {
                    target->parent = curPoint;
                    target->G = tempG;
                    target->F = calcF(target);
                }
            }

            // update the result point
            Point *resPoint = isInList(openList, &endPoint);
            if (resPoint)
                return resPoint;
        }
    }
    return NULL;
}

/**
 * Get the path
 * @param startPoint startPoint
 * @param endPoint endPoint
 * @param isIgnoreCorner isIgnoreCorner
 * @return list<Point *>
 */
std::list<Point *> Astar::GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner) {
    Point *result = getPath(startPoint, endPoint, isIgnoreCorner);
    std::list<Point *> path;

    // while there is a correct result
    while (result) {
        path.push_front(result);
        result = result->parent;
    }
    openList.clear();
    closeList.clear();
    return path;
}

/**
 * checks if the edge is in the list
 * @param list list
 * @param point point
 * @return Point
 */
Point *Astar::isInList(const std::list<Point *> &list, const Point *point) const {
    for (auto p : list)
        if (p->x == point->x && p->y == point->y)
            return p;
    return NULL;
}

/**
 * rerurns true if it can reach the point, false otherwise
 * @param point point
 * @param target target
 * @param isIgnoreCorner isIgnoreCorner
 * @return אtrue if it can reach the point, false otherwise
 */
bool Astar::isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const {
    //checks if in the bounds
    if (target->x < 0 || target->x > costMatrix.size() - 1
        || target->y < 0 || target->y > costMatrix[0].size() - 1
        || costMatrix[target->x][target->y] == 1
        || target->x == point->x && target->y == point->y
        || isInList(closeList, target))
        return false;
        // if not in the bounds
    else {
        if (abs(point->x - target->x) + abs(point->y - target->y) == 1)
            return true;
        else {
            if (costMatrix[point->x][target->y] == 0 && costMatrix[target->x][point->y] == 0)
                return true;
            else
                return isIgnoreCorner;
        }
    }
}

/**
 * getNumOfNodes
 * @return int
 */
int Astar::getNumOfNodes() const {
    return numOfNodes;
}

/**
 * getCost
 * @return cost
 */
int Astar::getCost() const {
    return cost;
}

/**
 * getSurroundPoints
 * @param point point
 * @param isIgnoreCorner isIgnoreCorner
 * @return vector<Point *>
 */
std::vector<Point *> Astar::getSurroundPoints(const Point *point, bool isIgnoreCorner) const {
    std::vector<Point *> surroundPoints;

    // runs through the sorround points
    for (int x = point->x - 1; x <= point->x + 1; x++)
        for (int y = point->y - 1; y <= point->y + 1; y++)
            if (isCanreach(point, new Point(x, y), isIgnoreCorner))
                surroundPoints.push_back(new Point(x, y));
    return surroundPoints;
}

/**
 * FindPath
 */
void Astar::FindPath() {
    if(this->Graph.size()!=Graph[0].size()){
        cout<<"Error Please Enter an NXN Matrix"<<endl;
        this->cost=0;
        this->numOfNodes=-1;
    }
    list<Point *> path = GetPath(this->startPoint, this->endPoint, false);
    for (auto &p : path) {
        numOfNodes++;
        this->path.push_back(Graph[p->x][p->y].getLocation());
    }
    for (auto &p : path) {
        // subtract 5 to get a correct result after we add 5 to the cost in the constructor.
        cost += costMatrix[p->x][p->y] - 5;
    }
}

/**
 * getPath
 * @return vector<int>
 */
const vector<int> &Astar::getPath() const {
    return path;
}

/**
 * Astar
 * @param Graph Graph
 * @param costs costs
 * @param entranceLocation entranceLocation
 * @param initlizeStartPoint initlizeStartPoint
 * @param initlizeEndPoint initlizeEndPoint
 */
Astar::Astar(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation,
             const vector<int> &initlizeStartPoint, const vector<int> &initlizeEndPoint) : Graph(Graph), costs(costs),
                                                                                           entranceLocation(
                                                                                                   entranceLocation),
                                                                                           initlizeStartPoint(
                                                                                                   initlizeStartPoint),
                                                                                           initlizeEndPoint(
                                                                                                   initlizeEndPoint) {
    Point startPoint(this->initlizeStartPoint[0], this->initlizeStartPoint[1]);
    this->startPoint = startPoint;
    Point endPoint(this->initlizeEndPoint[0], this->initlizeEndPoint[1]);
    this->endPoint = endPoint;
    //runs through the graph
    for (int i = 0; i < Graph.size(); ++i) {
        vector<int> vec;
        for (int j = 0; j < Graph[i].size(); ++j) {
            int cost = this->Graph[i][j].getCost();
            // update the cost if it is not -1, adds 5 to the cost.
            // after that we subtract 5 from the cost for getting correct costs.
            if (cost != -1) {
                cost += 5;
            }
            vec.push_back(cost);
        }
        this->costMatrix.push_back(vec);
    }

}

