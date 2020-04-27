#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include <stdbool.h>
#include "Node.h"
#include "Stack.h"


//Tree

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


static void getTreeSizeRecv(struct Node* node, int* count){
     *count=*count+1;
     if(node!=NULL){
	  //count=&swap;
	  if(node->right!=NULL){
	       getTreeSizeRecv(node->right,count);
	  }
	  if(node->left!=NULL){
	       getTreeSizeRecv(node->left,count);
	  }
     }
}

static int getTreeSizeIter(struct Node* node){
     int count=0;
     struct Node* stackNode=newNode(stackNode, node->type);
     bool isLeft=true;
     struct Node* temp=newNode(temp, node->type);
     temp=node;

     //REaliezed error in code: need to modify pushStack as to be able to take in nodes as well as values
     /*
     //Goes through the list. Each ndoe it finds, it adds to the stack.
     //When it needs to go backwards, goes through the stack.
     while ( sizeStack(stackNode)>0 || isRight){
	  //If there's a node, add to stack, incremnet count, and than go to it's left child
	  if(temp){
	       union Value NodeVal;
	       switch (node->type){
	       case i: NodeVal.i=node->value.i; break;
	       case ui: NodeVal.ui=node->value.ui; break;
	       case f: NodeVal.f=node->value.f; break;
	       case c: NodeVal.c=node->value.c; break;
	       }
	       pushStack(temp);
	       count++;
	       temp=temp->left;
	  }
	  //if there is no node, keep going back and go through the right of the children till you find a non-null children. than repeat step above.
	  else{
	       while(sizeStack(stackNode)>0){
		    temp=popStack(stackNode);
	       }
	  }


	  
     }
     */
     

     return count;
}
int getTreeSize(struct Node* node){
     /*
       int *count=malloc(sizeof(count));
       int count=getTreeSizeRecv(node);
       printf("Coutn size%d\n",*count);
       return *count;
     */
     int count=getTreeSizeIter(node);
     return count;
  
     
}


void createNodeChild(struct Node* parent, union Value NodeVal, bool isLeft){
     //struct Node* newNode(struct Node* node, int key, enum ValueType type){
     struct Node* child=newNode(child, parent->type);
     setNodeValue(child, NodeVal);
     if(isLeft) parent->left=child; else parent->right=child;
}

// Creates a bunch of nodes in the tree for testing purposes
void createBulkNodeChild(struct Node* parent,  union Value* NodeVal, int size){
     for(int i=0; i<size; i++){
    
     }
  
}


