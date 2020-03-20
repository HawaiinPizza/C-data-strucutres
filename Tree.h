#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include <stdbool.h>

//For colring purposes
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"


// Implenation of trees in the C programming langauge. Used for  educational purposes.

// Data Stuructres decleartions
//Enum, as to automate setting values.
enum ValueType{
     i,
     ui,
     f,
     c,
};

//Value is the acutal value a ndoe is stroign. It's made into a union, as to allow the tree to ipmlment multiple primitives.
union Value{
     int i;
     unsigned int ui;
     float f;
     char c;
     // Worry about this later. char str[20];
} Value;


// A node is the fundemtainal building block of a tree.
struct Node {
     //number used to sort the  tree.
     unsigned int Key;

     //To allow for multiple values
     union Value value;
     //To specify whihc type of value the tree uses
     enum ValueType type;

     //Setting up the links in teh tree.
     struct Node *left;
     struct Node *right;
     struct Node *parent;
}Node;


//Functions decleartions.

/// Node Functionals

////BC: take in node, and what is the valuetype: PC: Node is initlzied wiht it's value
struct Node* newNode(struct Node* node, int key, enum ValueType type){
     node=malloc(sizeof(node));
     node->Key=key;
     node->type=type;
     node->left=malloc(sizeof(node));
     node->right=malloc(sizeof(node));
     node->left=NULL;
     node->right=NULL;
     return node;
}


void printNode(struct Node* node){
     switch(node->type){
     case i: printf ("Key: %d\tValue: %d\n",node->Key,node->value.i ); break;
     case ui: printf("Key: %d\tValue: %d\n",node->Key,node->value.ui ); break;
     case f: printf ("Key: %d\tValue: %d\n",node->Key,node->value.f ); break;
     case c: printf ("Key: %d\tValue: %d\n",node->Key,node->value.c ); break;
     }
}

void printNodePretty(struct Node* node){
     switch(node->type){
     case i: printf (ANSI_COLOR_BLUE"Key: %d\t" ANSI_COLOR_YELLOW"Value: %d\n",node->Key,node->value.i ); break;
     case ui: printf(ANSI_COLOR_BLUE"Key: %d\t" ANSI_COLOR_YELLOW"Value: %d\n",node->Key,node->value.ui ); break;
     case f: printf (ANSI_COLOR_BLUE"Key: %d\t" ANSI_COLOR_YELLOW"Value: %d\n",node->Key,node->value.f ); break;
     case c: printf (ANSI_COLOR_BLUE"Key: %d\t" ANSI_COLOR_YELLOW"Value: %d\n",node->Key,node->value.c ); break;
     }
}

////BC: Takes in a node and posssiple value. PC: Node is intilzed with the current value.
void setNodeValue(struct Node* node, union Value NodeVal){
     switch(node->type){
     case i:
	  node->value.i=NodeVal.i; break;
     case ui:
	  node->value.ui=NodeVal.ui; break;
     case f:
	  node->value.f=NodeVal.f; break;
     case c:
	  node->value.c=NodeVal.c; break;
     }
  
}

//Creates a link between the two nodes. 
void setNodeLink(struct Node* parentNode, struct Node* childNode, bool isLeft){
     childNode->parent=parentNode;
     if(isLeft)
	  parentNode->left=childNode;
     else{
	  parentNode->right=childNode;
     }

}


//Tree/Nodes Operatoins

void printNodeChildren(struct Node* node, int count){
     if(node!=NULL){
	  for(int i=0; i<count; i++){
	    printf("\t");
	    
	  }
	  count++;
	  printNode(node);
	  if(node->right!=NULL){
	       printf("%d left:\t",count);  printNodeChildren(node->right, count);
	  }
	  if(node->left!=NULL){
	       printf("%d right:\t",count);  printNodeChildren(node->left, count);
	  }
     }
  
}


void printTree(struct Node* node){
     printNodeChildren(node, 0);
}

void createNodeChild(struct Node* parent, int key, union Value NodeVal, bool isLeft){
  //struct Node* newNode(struct Node* node, int key, enum ValueType type){
  struct Node* child=newNode(child, key, parent->type);
  setNodeValue(child, NodeVal);
  if(isLeft) parent->left=child; else parent->right=child;
}

void createBulkNodeChild(struct Node* parent, int key, union Value* NodeVal){
  
}


