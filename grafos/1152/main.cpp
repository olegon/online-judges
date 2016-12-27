/*
Estradas Escuras
https://www.urionlinejudge.com.br/judge/pt/problems/view/1152
*/

#include <iostream>
#include <algorithm>

using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    Edge* edge;
};

// A structure to represent a subset for union-find
struct Subset
{
    int parent;
    int rank;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();

    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

// Creates a graph with V vertices and E edges
void destroyGraph(Graph *graph)
{
    delete[] graph->edge;
    delete graph;
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(Subset *subsets, int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {


        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

int KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    Edge *result = new Edge[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges

    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(Edge), myComp);

    // Allocate memory for creating V ssubsets
    Subset *subsets = new Subset[V];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    // printf("Following are the edges in the constructed MST\n");
    int tamanho = 0;
    for (i = 0; i < e; ++i) tamanho += result[i].weight;

    delete[] result;
    delete[] subsets;

    return tamanho;
}

int main (void) {
    int M, N;


    while (cin >> M >> N, M != 0 || N != 0) {
        Graph *graph = createGraph(M, N);
        int tamanhoOriginal  = 0;

        for (int i = 0; i < N; i++) {
            int X, Y, Z;

            cin >> X >> Y >> Z;


            graph->edge[i].src = X;
            graph->edge[i].dest = Y;
            graph->edge[i].weight = Z;

            tamanhoOriginal += Z;
        }

        cout << tamanhoOriginal - KruskalMST(graph) << endl;

        destroyGraph(graph);
    }

    return 0;
}
