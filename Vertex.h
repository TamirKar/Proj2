

#ifndef UNTITLED19_VERTEX_H
#define UNTITLED19_VERTEX_H

/**
 * Vertex - represemts the vertices in the graph
 */
class Vertex {
private:
    int location;
    int cost;

public:

    /**
     * Vertex
     * @param id id
     * @param cost cost
     */
    Vertex(int id, int cost);

    /**
     * Vertex
     */
    Vertex();

    /**
     * getCost
     * @return int
     */
    int getCost() const;

    /**
     * getLocation
     * @return int
     */
    int getLocation() const;
};

#endif //UNTITLED19_VERTEX_H
