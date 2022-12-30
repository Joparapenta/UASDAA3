#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int source;
    int destination;
    int weight;
};

// Structure to represent a node in the graph
struct Node
{
    int vertex;
    int weight;
};

// Comparison function to sort the edges in non-decreasing order
// based on their weight
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning tree of the given graph
void prim(vector<Edge> edges, int num_vertices)
{
    // Sort the edges in non-decreasing order
    sort(edges.begin(), edges.end(), compare);

    // Create a vector to store the minimum spanning tree
    vector<Edge> mst;

    // Create a vector to store the visited vertices
    vector<int> visited(num_vertices, false);

    // Create a vector of Node structures to represent the priority queue
    vector<Node> pq;

    // Add the first vertex to the priority queue
    pq.push_back({0, 0});

    // Run the loop while there are vertices in the priority queue
    while (!pq.empty())
    {
        // Extract the vertex with the minimum weight
        Node node = pq.front();
        pq.erase(pq.begin());

        int vertex = node.vertex;
        int weight = node.weight;

        // If the vertex has already been visited, skip it
        if (visited[vertex])
        {
            continue;
        }

        // Mark the vertex as visited
        visited[vertex] = true;

        // Add the edge to the minimum spanning tree
        if (weight != INT_MAX)
        {
            mst.push_back({vertex, weight, weight});
        }

        // Update the priority queue with the new edges
        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i].destination;
            int w = edges[i].weight;

            // Skip the edge if it leads to a visited vertex
            if (visited[v])
            {
                continue;
            }

            // Update the priority queue with the new edge
            pq.push_back({v, w});
        }
        // Print the current state of the algorithm
        cout << "Extracted vertex: " << vertex << " with weight " << weight << endl;
        cout << "Visited vertices: ";
        for (int i = 0; i < num_vertices; i++)
        {
            cout << i << " ";
        }
        cout << endl;

    }



    // Print the minimum spanning tree
    cout << "The minimum spanning tree is:" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].source << " - " << mst[i].destination << " : " << mst[i].weight << endl;
    }
}

int main()
{
    // Create a vector to store the edges of the graph
    vector<Edge> edges;

   edges.push_back({0, 1, 7});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 2, 8});
    edges.push_back({1, 3, 9});
    edges.push_back({1, 4, 7});
    edges.push_back({2, 4, 5});
    edges.push_back({3, 4, 15});
    

    // Get the number of vertices in the graph
    int num_vertices = 5;

    // Call the prim function to find the minimum spanning tree
    prim(edges, num_vertices);

    return 0;
}
