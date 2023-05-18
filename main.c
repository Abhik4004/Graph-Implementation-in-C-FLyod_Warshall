#include "graph.h"

int no_vertices;

typedef struct Components{
    int s; //source
    int d; //destination
    int ch; //choice
}req;

req info;



int main()
{
    printf("\n");
    printf("\t\t----------------------------------** GRAPH IMPLEMENTATION **----------------------------------\t\t");
    printf("\n");
    printf("\t\t------------------------------------------- WELCOME -------------------------------------------\t\t");
    printf("\n");

    int start;
    
    printf("\nEnter no of vertices: ");
    scanf("%d", &no_vertices);

    printf("\nTo terimnate enter -1 -1");

    int adj[no_vertices][no_vertices],visited[no_vertices];

    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            adj[i][j]=0;
        }
        
    }

    printf("\n");
    
    while(info.s!=-1 && info.d!=-1)
    {
    printf("Enter an Edge from node (0 to %d) to node(0 to %d): ",no_vertices, no_vertices);
    scanf("%d%d", &info.s, &info.d);
    adj[info.s][info.d]=1;
    adj[info.d][info.s]=1;
    }


    do
    {
        printf("\nEnter 1 for BFS || Enter 2 for DFS || Enter 3 for printing adj matrix || Enter 4 to calculate shortest path between two nodes || Enter 5 to exit  : ");
        scanf("%d", &info.ch);

        switch(info.ch)
        {
            case 1: 
                printf("Enter the vertex from which do you want to start?\n");
                scanf("%d", &start);
                bfs(adj, start);
                break;

            case 2: 
                printf("Enter the vertex from which you wanna start for DFS?\n");
                scanf("%d", &start);
                for (int i = 0; i < no_vertices; i++)
                {
                    visited[i]=0;
                }
                dfs(adj, visited, start);
                break;

            case 3:
                print_graph(adj);
                break;
            
            case 4:
                printf("Enter from which node to which node you want to calculate the shortest distance?\n");
                int first, last;
                printf("From: \n");
                scanf("%d", &first);
                printf("UpTo : \n");
                scanf("%d", &last);
                // shortestPath(adj, no_vertices, first, last);
                floydWarshall(adj, no_vertices, first, last);
                break;

            case 5:
                printf("\n");
                printf("\t\t-------- THANK YOU --------\t\t");
                break;

        }

        

    } while (info.ch != 5);

    return 0;
}