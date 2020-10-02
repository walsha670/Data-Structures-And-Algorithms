#include <stdio.h> 
#include <stdlib.h>

#define NUM_NODES 6
#define NUM_DESTS 4

//node, needs flag to determine whether its been visited, char value for its name and pointer to next node in pathway
typedef struct node { 

    char name;
    int VISIT_flag; 
    struct node* next[NUM_DESTS]; 

}node; 

//intialise all functions
void Print_PATHWAYS(node * root);
node* New_Node(char name); 
void Add_Edge(node* start, node* end); 
void change_Flags(node* nodes[]);
void DFS(node* root);
void BFS(node* root);


int main(){ 

    printf("\nresults:\n");
    node* nodes[NUM_NODES];
    node* root = nodes[0];
    char name = 'A';
    
    //simple for loop creating the nodes needed for each graph
    for(int i = 0; i < NUM_NODES; i++){
        nodes[i] = New_Node(name);
        name++;
    }

    //adding the edges for the given graph
    Add_Edge(nodes[0], nodes[1]);
    Add_Edge(nodes[0], nodes[3]);
    Add_Edge(nodes[0], nodes[4]);
    Add_Edge(nodes[1], nodes[2]);
    Add_Edge(nodes[1], nodes[3]);
    Add_Edge(nodes[2], nodes[1]);
    Add_Edge(nodes[2], nodes[3]);
    Add_Edge(nodes[3], nodes[5]);
    Add_Edge(nodes[4], nodes[3]);
    Add_Edge(nodes[5], nodes[2]);

    change_Flags(nodes);

    printf("DFS: ");
    DFS(nodes[0]);
    printf("\n\n");

    change_Flags(nodes);

    printf("BFS: ");
    BFS(nodes[0]);
    printf("\n\n");

    return 0; 
} 

//function creates a new vertex and sets its attributes
node* New_Node(char name){

    node* New_Node = (node*)malloc(sizeof(node)); 
    New_Node->name = name; 

    for(int i = 0; i < NUM_DESTS; i++){
        New_Node->next[i] = NULL; 
    }
    return New_Node;
}

//function to add edges between vertices using the next pointers
void Add_Edge(node* start, node* end){
    
    int i = 0;
    node* current = start->next[i];

    while(current != NULL){
        i++;
        current = start->next[i];
    }
    start->next[i] = end;
    //printf("\nAdding Edge\n");

}

//makes all nodes unvisited for the next graph search
void change_Flags(node* nodes[]){

    for(int i = 0; i < NUM_NODES; i++){
        nodes[i]->VISIT_flag = 0;
    }
}

//performs Depth First Search on the graph using recursion
void DFS(node* root) { 

    //if the vertex is not visited
    if(root->VISIT_flag != 1){

        //print the name and mark as visited
        printf("%c ", root->name);
        root->VISIT_flag = 1;
        int i = 0;
        node* current = root->next[i];

        //recursive call this function on all the neighbours
        while(current != NULL){
            DFS(current);
            i++;
            current = root->next[i];
        }
    }
}

//performs Breath First Search on the graph using recursion
void BFS(node* root){ 

    //if the flag is not print the vertex and change the flag
    if(root->VISIT_flag != 1){
        printf("%c ", root->name);
        root->VISIT_flag = 1;
    }
    //print all neighbours that havent been visited
    Print_PATHWAYS(root);

    int i = 0;
    node* current = root->next[i];

    //print all the neighrbours for ech neighbour that havent been visited
    while(current != NULL){

        Print_PATHWAYS(current);  

        i++;
        current = root->next[i];
    }
}

//prints all the neighbours that havent been visited for a node
void Print_PATHWAYS(node * root){

    int i = 0;
    node* current = root->next[i];

    while(current != NULL){
        if(current->VISIT_flag != 1){
            printf("%c ", current->name);
            current->VISIT_flag = 1;
        }
        i++;
        current = root->next[i];
    }

}


