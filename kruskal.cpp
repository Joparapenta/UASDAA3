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

// Comparison function to sort the edges in non-decreasing order
// based on their weight
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

// Function to find the root of the given vertex
int find(vector<int>& parent, int vertex)
{
    if (parent[vertex] == vertex)
    {
        return vertex;
    }

    return find(parent, parent[vertex]);
}

// Function to find the minimum spanning tree of the given graph
void kruskal(vector<Edge> edges, int num_vertices)
{
    // Sort the edges in non-decreasing order
    sort(edges.begin(), edges.end(), compare);

    // Create a vector to store the minimum spanning tree
    vector<Edge> mst;

    // Create a vector of Node structures to represent the disjoint sets
    vector<int> parent(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        parent[i] = i;
    }

    // Run the loop until the minimum spanning tree is complete
    for (int i = 0; i < edges.size(); i++)
    {
        int source = edges[i].source;
        int destination = edges[i].destination;
        int weight = edges[i].weight;

        // Find the root of the source and destination vertices
        int root1 = find(parent, source);
        int root2 = find(parent, destination);

        // If the root of the source and destination vertices are the same,
        // skip the edge as it would create a cycle
        if (root1 == root2)
        {
            continue;
        }

        // Add the edge to the minimum spanning tree
        mst.push_back({source, destination, weight});

         // Print the edge and its weight
        cout << "Adding edge: " << source << " - " << destination << " : " << weight << endl;

        // Union of the two disjoint sets
        parent[root1] = root2;
    }

    // Print the minimum spanning tree
    cout << "Minimum spanning tree:" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].source << " - " << mst[i].destination << " : " << mst[i].weight << endl;
    }
}

int main()
{
    int num_vertices = 5;
    int num_edges = 7;

    vector<Edge> edges;

   edges.push_back({0, 1, 7});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 2, 8});
    edges.push_back({1, 3, 9});
    edges.push_back({1, 4, 7});
    edges.push_back({2, 4, 5});
    edges.push_back({3, 4, 15});

    kruskal(edges, num_vertices);
    return 0;
}
