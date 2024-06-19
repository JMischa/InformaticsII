#include <stdio.h>

#define MAX_VERTICES 20
#define INF 1000

int graph[MAX_VERTICES][MAX_VERTICES];

void Dijkstra(int num_v, int start){
    int dist[MAX_VERTICES];
    int inDST[MAX_VERTICES];

    //Initialization//
    for(int i = 0; i < num_v; i++){
        dist[i] = INF;
        inDST[0] = 0;
    }
    dist[start] = 0;

    for(int iter = 0; iter < num_v - 1; iter++){
        int minDist = INF;
        int minIndex = -1;

        for(int v = 0; v < num_v; v++){
            if(inDST[v] == 0 && dist[v] <= minDist){
                minDist = dist[v];
                minIndex = v;
            }
        }
        inDST[minIndex] = 1;
        if(dist[minIndex] == INF || minIndex == -1){
            continue;
        }
        
        // Relaxation
        for(int v = 0; v < num_v; v++){
            if(inDST[v] == 1 || v == minIndex || graph[minIndex][v] == INF){
                continue;
            }
            int new_dist = dist[minIndex] + graph[minIndex][v];
            if(new_dist < dist[v]){
                dist[v] = new_dist;
            }
        }
    }
    printf("Shortest distances from vertex %d:\n", start);
    for(int i = 0; i < num_v; i++){
        if(dist[i] == INF){
            printf("Vertex %d: Unable to reach\n", i);
        }
        else{
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}


int main(){
    int num_vertices, num_edges;

    scanf("%d, %d", &num_vertices, &num_edges);

    for(int i = 0; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            if(i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < num_edges; i++){
        int s, t, w;
        scanf("%d, %d, %d", &s, &t, &w);
        graph[s][t] = w;
    }

    Dijkstra(num_vertices, 0);

    return 0;
}
