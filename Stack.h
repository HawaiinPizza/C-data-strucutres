#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include <stdbool.h>


void printStack(struct Node* root){
     struct Node* temp=root;
     while(temp){
	  printNode(temp);
	  temp=temp->right;
     }
}
int sizeStack(struct Node* root){
     int i=0;
     struct Node* temp=root;
     while(temp){
	  i++;
	  temp=temp->right;
     }
     return i;
     
}

void pushStack(struct Node* root, union Value NodeVal){
     struct Node* temp=root;
     struct Node* tempNext=root->right;
     while(temp){
	  tempNext=temp;
	  temp=temp->right;
     }
     temp=newNode(temp, root->type);
     setNodeValue(temp, NodeVal);
     tempNext->right=temp;
     temp->parent=tempNext;
}


