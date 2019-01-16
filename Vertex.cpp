
#include "Vertex.h"

/**
 * Vertex
 * @param id id
 * @param cost cost
 */
Vertex::Vertex(int id, int cost) : location(id), cost(cost) {}

/**
 * getLocation
 * @return int
 */
int Vertex::getLocation() const {
    return location;
}
/**
 * default constructor
 */
Vertex::Vertex() {}

/**
 * getCost
 * @return int
 */
int Vertex::getCost() const {
    return cost;
}



