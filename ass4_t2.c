#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
//

//declaring djikstra function
void DJKS(int graph[SIZE][SIZE], int startnode);
///to convert ints to char node names

void char_index(int vertex);
//chose matrix, faster than linked list and the data of the graph isnt wasting to much memory


void DJKS(int graph[SIZE][SIZE], int start){
 
    int cost[SIZE][SIZE], dist[SIZE],
     pred[SIZE], perm[SIZE],
     curr, min, distance,
     predeccesor;

    //initialise the cost matrix, large value is assigned to any connection that doesnt exist
    //otherwise the cost value is as seen in the matrix
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(graph[i][j] == 0){
                cost[i][j] = 999;
            }
            else{
                cost[i][j] = graph[i][j];
            }
        }
    }

    //initialise the distance, predeccesor and permanent arrays
    for(int i = 0; i < SIZE; i++){
        dist[i] = cost[start][i];
        pred[i] = start;
        perm[i] = 0;
    }
    
    //setting  the distance from A to itself
    dist[start] = 0;
    perm[start] = 1;
    int count = 1;
    curr = 0;


    printf("\nVertices in order of being made: ");
    char_index(start);

    //loop through until all vertices are permanent while printing them
    while(count < SIZE){
        min = 9999;

        //loop checking for shortest distance for curr's neighbours
        for(int i = 1; i < SIZE; i++){
            distance = dist[curr] + cost[curr][i];

            //if the new path is shorter, update dist array and predeccsor
            if(distance < dist[i] && perm[i] == 0){
                dist[i] = distance;
                pred[i] = curr;
            }
            //if the distance to i is less than the paths minimum, update mim and curr
            if(min > dist[i] && perm[i] == 0){
                min = dist[i];
                curr = i;
            }
        }
        //make curr permanent and print
        perm[curr] = 1;
        printf(" -> ");
        char_index(curr);
        count++;
    }
    printf("\n");

    //printing the distance and path for each vertex
    for(int i = 1; i < SIZE; i++){

        printf("\n\nDistance of Vertex: ");
        char_index(i);
        printf(" from A = %d\n", dist[i]);
        printf("Pathway = ");
            
        predeccesor = i;
        char_index(predeccesor);

        //loop printing the predeccesors
        while(predeccesor != start){
            predeccesor = pred[predeccesor];
            printf(" - ");
            char_index(predeccesor);
        }
    }
    printf("\n\n");
}






int main(){ 
//intitialising the matrix
   int graph[SIZE][SIZE] = {{0,1,3,0,0,10,0}, 
                            {1,0,1,7,5,0,2}, 
                            {3,1,0,9,3,0,0}, 
                            {0,7,9,0,2,1,12}, 
                            {0,5,3,2,0,2,0}, 
                            {0,0,0,1,2,0,0}, 
                            {0,2,0,12,0,0,0}}; 
   
    DJKS(graph, 0); 
   
    return 0; 
}

//function to print the corresponding char for each index
void char_index(int vertex){

    char node = (vertex + 'A');
    printf("(%c)", node);
}