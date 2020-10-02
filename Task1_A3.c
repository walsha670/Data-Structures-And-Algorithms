#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//load array with given input
char string_input[] = {'F', 'L', 'O', 'C', 'C', 'I', 'N', 
'A', 'U', 'C', 'I', 'N', 'I', 'H', 'I', 'L', 'I', 'P', 
'I', 'L', 'I', 'F', 'I', 'C', 'A', 'T', 'T', 'I', 'O', 'N'};


//set up a structure for nodes in the tree, key which is the char and pointers to left and right children
struct node 
{ 
    char key; 
    struct node *left, *right; 
}; 
   
//create new node for the tree, allocates appropriate memory, fills in top spot with the character, 
//sets children to NULL
struct node *newNode(char item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
   
} 


//insert initial node with using newnode then fills in children nodes, recurs down table to check if 
struct node* insert(struct node* node, char key) 
{ 
    // If the tree is empty, return a new node 
    if (node == NULL) return newNode(key); 
  
    // Otherwise, recur down the tree 
    if (key == node->key)
        node->left  = insert(node->left, key);
    else if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    
  
    // return the (unchanged) node pointer 
    return node; 
} 
   
//traverse in order 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%c", root->key); 
        inorder(root->right); 
    } 
} 


/*int search(char string_input[], char randvar){
   for(int i=1; i <= 30; i++) {

   if(string_input[i]== randvar){
    return 1;
   }
   }

}*/

int search(struct node *root, char randvar) {
    
    if (root != NULL) 
    {   
        if (randvar == root->key) {
        return 1;
        }
        else {
        search(root->left, randvar);
        search(root->right, randvar);
        } 
        
    }

    

}

void deleteTree(struct node *root) {
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
    root = NULL;

}


   
int main(){



struct node *root = NULL; 
root = insert(root, string_input[0]); 

printf("%s", "ADDING: ");
printf("%s \n", string_input);


for(int i=1; i <= 30; i++) {

insert(root, string_input[i]);

}

printf("%s", "SORTED: ");
inorder(root);
printf("%s", "\n");
srand((unsigned)time (NULL));
char randchar1 = 'A' + (rand() % 26);
char randchar2 = 'A' + (rand() % 26);
printf("random character 1: \t%c\nrandom character 2: \t%c\n ", randchar1, randchar2);


char tbc = randchar1;
if(search(string_input, tbc) == 1){
printf("in tree\n");
}
else(printf("not in tree\n"));

tbc = randchar2;
if(search(string_input, tbc) == 1){
printf("in tree\n");
}
else(printf("not in tree\n"));

deleteTree(root);
printf("Tree deleted\n");

}



   
