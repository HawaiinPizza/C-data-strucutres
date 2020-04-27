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

  //To allow for multiple values
  union Value value;
  //To specify whihc type of value the tree uses
  enum ValueType type;

  //Setting up the links in teh tree.
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  struct Node **links;
}Node;


//BC: take in node, and what is the valuetype: PC: Node is initlzied wiht it's value
struct Node* newNode(struct Node* node, enum ValueType type){
  node=malloc(sizeof(node));
  node->type=type;
  //For grpahs, which can have multiple links, i abstracted having hte left, right and parent node to an pointer list of nodes.
  //node->links=calloc(3,sizeof(node));

  
  node->left=malloc(sizeof(node->left));
  node->left->value.i=0;
  node->links=malloc(5*sizeof(node));

  node->left=malloc(sizeof(node));
  node->right=malloc(sizeof(node));
  node->parent=malloc(sizeof(node));

  node->links[0]= node->left ;
  node->links[1]= node->right ;
  node->links[2]= node->parent ;


  node->left=NULL;
  node->right=NULL;
  node->parent=NULL;

  return node;
}

void deleteNode(struct Node* node){
	free(node->left);
	node->left=NULL;
	free(node->right);
	node->right=NULL;
	free(node);
	node=NULL;
}


//BC: Takes in a node and posssiple value. PC: Node is intilzed with the current value.
void setNodeValue(struct Node* node, union Value NodeVal){
	switch(node->type){
		case i: node->value.i=NodeVal.i; break;
		case ui: node->value.ui=NodeVal.ui; break;
		case f: node->value.f=NodeVal.f; break;
		case c: node->value.c=NodeVal.c; break;
	}
}


//Creates a link between the two nodes. 
void setNodeLink(struct Node* parentNode, struct Node* childNode, bool isLeft){
	childNode->parent=parentNode;
	if(isLeft) parentNode->left=childNode;
	else parentNode->right=childNode;
}


void printNode(struct Node* node){
	switch(node->type){
		case i: printf ("Value: %d\n",node->value.i ); break;
		case ui: printf("Value: %d\n",node->value.ui ); break;
		case f: printf ("Value: %d\n",node->value.f ); break;
		case c: printf ("Value: %d\n",node->value.c ); break;
	}
}

void printNodePretty(struct Node* node){
	switch(node->type){
		case i: printf (ANSI_COLOR_BLUE"Value: %d\n",node->value.i ); break;
		case ui: printf(ANSI_COLOR_BLUE"Value: %d\n",node->value.ui ); break;
		case f: printf (ANSI_COLOR_BLUE"Value: %d\n",node->value.f ); break;
		case c: printf (ANSI_COLOR_BLUE"Value: %d\n",node->value.c ); break;
	}
}
