// Prim's Algorithm implementation in C++

#include <cstring>
#include <iostream>
using namespace std;



// initialize the number of vertices in graph
#define V 6
int minimum_cost=0;
// create a 2d array of size 6x6
//making an adjacency matrix to represent the graph

int G[][6] = {{0, 3, 0, 0, 0, 1},
               {3, 0, 2, 1, 10, 0},
               {0, 2, 0, 3, 0, 5},
               {0, 1, 3, 0, 5, 0},
               {0, 10,0, 5, 0, 4},
               {1, 0, 5, 0, 4, 0}};

int main() {
    int no_edge;  // number of edge

    // create a array to track traveled vertex
    // traveled will become true otherwise false
    int traveled[V];

    // set traveled false initially
    memset(traveled, false, sizeof(traveled));

    // set number of edge to 0
    no_edge = 0;


// The minimum number of edges in a spanning tree will always be less than (V - 1),
// where V represents the total number of vertices in the graph.

    // select the first vertex and make it as true since it has already travelled.
    traveled[0] = true;

    int x;  //  row number
    int y;  //  column number

    // print for edge and weight
    cout << "Path"
         << "  : "
         << "Cost";
    cout << endl;
    while (no_edge < V - 1) {
        // Iterate through each vertex in set S and identify all its neighboring vertices.
        // Calculate the distance from the vertex visited in step 1.
        // If the vertex is already included in set S, ignore it; otherwise,
        // select the closest vertex to the visited vertex in step 1 as the next choice.

        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (traveled[i]) {
                for (int j = 0; j < V; j++) {
                    if (!traveled[j] && G[i][j]) {  // not in traveled and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        traveled[y] = true;
        no_edge++;
        minimum_cost+=G[x][y];
    }
cout<<"The minimum cost is: "<<minimum_cost<<endl;
    return 0;
}
