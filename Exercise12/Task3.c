#include <stdio.h>

#define MAX_VERTICES 20
#define INF 1000

struct Edge{
    int dest;  //initialize to -1
    int weight;
};

struct Graph{
    int num_vertices;
    struct Edge array[MAX_VERTICES][MAX_VERTICES];
};

struct Graph creategraph(int num_vertices){
    struct Graph graph;
    graph.num_vertices = num_vertices;

    for(int i = 0; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            graph.array[i][j].dest = -1;
            graph.array[i][j].weight = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight){
    int i = 0;
    while(graph ->array[src][i].dest != -1){
        i++;
    }
    graph ->array[src][i].dest = dest;
    graph ->array[src][i].weight = weight;
}

int dist[MAX_VERTICES];
int instack[MAX_VERTICES];

int spfa(struct Graph* graph, int u){
    instack[u] = 1;

    int edge_idx = 0;
    while(graph ->array[u][edge_idx].dest != -1){
        int v = graph ->array[u][edge_idx].dest;
        int weight = graph ->array[u][edge_idx].weight;

        //Relaxation
        int new_dist = dist[u] + weight;
        if(new_dist < dist[v]){
            dist[v] = new_dist;

            if(instack[v] == 0){
                if(spfa(graph, v) == -1){
                    return -1;
                }
            }
            else{
                return -1;
            }
        }
        edge_idx++;
    }
    instack[u] = 0;
    return 0;
}


int main(){
    int num_vertices, num_edges;

    scanf("%d, %d", &num_vertices, &num_edges);

    struct Graph graph = creategraph(num_vertices);

    for(int i = 0; i < num_edges; i++){
        int from, to, w;
        scanf("%d, %d, %d", &from, &to, &w);
        addEdge(&graph, from, to, w);
    }

    int num_v = graph.num_vertices;
    int start = 0;

    for(int i = 0; i < num_v; i++){
        dist[i] = INF;
        instack[i] = 0;
    }
    dist[start] = 0;

    if(spfa(&graph, start) == -1){
        printf("Graph contains a negative weight cycle\n");
    }
    else{
        printf("Shortest distances from vertex %d\n", start);
        for(int i = 0; i < num_v; i++){
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
    return 0;
}
