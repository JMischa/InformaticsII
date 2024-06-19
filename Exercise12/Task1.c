#include <stdio.h>

#define MAX_VERTICES 20
#define INF 1000

int graph[MAX_VERTICES][MAX_VERTICES];


int primMST(int num_v){
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int inMST[MAX_VERTICES];
    
    //Initialization//
    for(int i = 0; i < num_v; i++){
        key[i] = INF;
        inMST[i] = 0;
    }
    
    key[0] = 0; //set starting node to 0//
    parent[0] = -1;

    int totalWeight = 0; //set the total weight to 0//

    //go through entire graph//
    for(int iter = 0; iter < num_v; iter++){
        int u;
        int minKey = INF;

        for(int v = 0; v < num_v; v++){
            if(inMST[v] == 0 && key[v] < minKey){
                minKey = key[v];
                u = v;
            }
        }
        printf("Add new node %d\n", u);
        inMST[u] = 1;
        totalWeight += key[u];

        for(int v = 0; v < num_v; v++){
            if(v == u || inMST[v] == 1 || graph[u][v] == INF){
                continue;
            }

            int new_weight = graph[u][v];
            if(new_weight < key[v]){
                parent[v] = u;
                key[v] = new_weight;
            } 
        }
    }

    //print edges in the MST//
    printf("Edges in the minimum spanning tree:\n");
    for(int i = 1; i < num_v; i++){
        printf("%d - %d: %d\n", parent[i], i, key[i]);
    }
    return totalWeight;
}


int main() {
    int num_vertices, num_edges;

    scanf("%d, %d", &num_vertices, &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int s, t, w;
        scanf("%d, %d, %d", &s, &t, &w);
        graph[s][t] = w;
        graph[t][s] = w;
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] == INF)
            printf("x ");
        else
            printf("%d ", graph[i][j]);
    }
    printf("\n");
}

    int res = primMST(num_vertices);
    printf("The total weight of the MST is %d.\n", res);

    return 0;
}
