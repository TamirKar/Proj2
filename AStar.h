#ifndef UNTITLED19_ASTAR_H
#define UNTITLED19_ASTAR_H


#include <vector>
#include <list>
#include "Searcher.h"
using namespace std;
const int kCost1 = 10;
const int kCost2 = 10;
struct Point
{
    int x, y;
    int F, G, H;
    Point *parent;
    Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL){}
    Point() :x(0), y(0), F(0), G(0), H(0), parent(NULL){}
};

/**
 * Astar
 */
class Astar : public Searcher
{
public:
    Astar(const vector<vector<Vertex>> &Graph, const vector<int> &costs, int entranceLocation,
          const vector<int> &initlizeStartPoint, const vector<int> &initlizeEndPoint);
    std::list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    Point *getPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
    bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;
    Point *isInList(const std::list<Point *> &list, const Point *point) const;
    Point *getLeastFpoint();
    int calcG(Point *temp_start, Point *point);
    int calcH(Point *point, Point *end);
    int calcF(Point *point);
    void FindPath() override;
    int getNumOfNodes() const;
    int getCost() const;

    const vector<int> &getPath() const;

private:
    vector<vector<Vertex>> Graph;
    vector<int> costs;
    int numOfNodes=-1;
    int cost;
    int entranceLocation;
    vector<int>initlizeStartPoint;
    vector<int>initlizeEndPoint;
    Point startPoint;
    Point endPoint;
    std::vector<std::vector<int>> costMatrix;
    std::list<Point *> openList;
    std::list<Point *> closeList;
    vector<int>path;
};


#endif //UNTITLED19_ASTAR_H
