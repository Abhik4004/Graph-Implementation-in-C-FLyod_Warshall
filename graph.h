#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF INT_MAX

int no_vertices;

//prototyping here:
void print_graph(int adj[no_vertices][no_vertices]);
void bfs(int adj[][no_vertices], int start);
void dfs(int adj[][no_vertices], int visited[], int start);
void floydWarshall(int adj[][no_vertices], int numVertices, int source, int destination);


void bfs(int adj[][no_vertices], int start)
{

    FILE *BFS = fopen("BFS.txt", "w");
    int *visited, *queue;
    int front = 0, rear = -1;

    visited = (int*)calloc(no_vertices, sizeof(int));
    queue = (int*)malloc(no_vertices * sizeof(int));

    queue[++rear] = start;
    visited[start] = 1;

    fprintf(BFS, "BFS: ", start);
    while (front <= rear)
    {
        start = queue[front++];
        printf("%d\t", start);

        fprintf(BFS, " %d\t", start);

        for (int i = 0; i < no_vertices; i++)
        {
            if (adj[start][i] == 1 && visited[i] != 1)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    free(visited);
    free(queue);
    fclose(BFS);
}



void dfs(int adj[][no_vertices], int visited[], int start)
{

    printf("%d\t", start);

    visited[start] = 1;

    for (int i = 0; i < no_vertices; i++)
    {
        if (visited[i] != 1 && adj[start][i] == 1)
        {
            dfs(adj, visited, i);
        }
    }

}


void print_graph(int adj[no_vertices][no_vertices])
{
    FILE *fp = fopen("matrix.txt", "w");
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            printf(" %d  ",adj[i][j]);
            fprintf(fp, " %d ||", adj[i][j]);
        }
        printf("\n");
        fprintf(fp, "\n");
        
    }
    fclose(fp);
    
}


void floydWarshall(int adj[][no_vertices], int numVertices, int source, int destination)
{
    int distance[no_vertices][no_vertices];
    int i, j, k;

    FILE *path = fopen("Shortest Path.txt", "w");
    fclose(path);

    path = fopen("Shortest Path.txt", "a");

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (adj[i][j] == 0)
                distance[i][j] = INT_MAX;
            else
                distance[i][j] = adj[i][j];
        }
    }

    for (k = 0; k < numVertices; k++) {
        for (i = 0; i < numVertices; i++) {
            for (j = 0; j < numVertices; j++) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Printing the shortest path distance
    if (distance[source][destination] == INT_MAX) {
        printf("No path from node %d to node %d\n", source, destination);
        fprintf(path, "No path from node %d to node %d\n", source, destination);
    } else {
        printf("Shortest distance from node %d to node %d: %d\n", source, destination, distance[source][destination]);
        fprintf(path, "Shortest distance from node %d to node %d: %d\n", source, destination, distance[source][destination]);
    }

    fclose(path);
}

#endif