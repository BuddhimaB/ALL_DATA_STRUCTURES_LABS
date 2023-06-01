#include <iostream>
#include <limits>
using namespace std;

#define V 6

int minDistance(int destination[], bool sptSet[]) {
    int min = numeric_limits<int>::max();
    int min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && destination[v] <= min) {
            min = destination[v];
            min_index = v;
        }
    }

    return min_index;
}

void printFinal(int dist[], int n, int src) {
    cout << "Vertex Distances from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        cout << "City " << src << " -> City " << i << " : " << dist[i] << endl;
    }
}

void averageTime(int dist[], int src) {
    int sum = 0;
    for (int i = 0; i < V; i++) {
        sum = sum + dist[i];
    }
    float average = (float)(sum) / 5;
    printf("Average time taken to travel from city %d to a certain city is %f", src, average);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printFinal(dist, V, src);
    averageTime(dist, src);
}

int main() {
    int graph[V][V] = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    dijkstra(graph, 4);

    return 0;
}
