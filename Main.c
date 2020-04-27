#include<stdlib.h>
#include<stdio.h>
#include "Tree.h"
#include<assert.h>




int mainTree(){
  struct Node* root;
  newNode(root,  i);
  union Value NodeVal;
  //deleteNode(root);

  NodeVal.i=1;
  setNodeValue(root, NodeVal);

  NodeVal.i=2;
  createNodeChild(root,  NodeVal, false);
  createNodeChild(root,  NodeVal, true);

  NodeVal.i=3;
  createNodeChild(root->left,  NodeVal, false);
  createNodeChild(root->left,  NodeVal, true);

  NodeVal.i=4;
  createNodeChild(root->right,  NodeVal, false);
  createNodeChild(root->right,  NodeVal, true);

  NodeVal.i=5;
  createNodeChild(root->left->left, NodeVal, false);
  createNodeChild(root->left->left, NodeVal, true);
     
  NodeVal.i=6;
  createNodeChild(root->left->right, NodeVal, false);
  createNodeChild(root->left->right, NodeVal, true);

  NodeVal.i=7;
  createNodeChild(root->right->left, NodeVal, false);
  createNodeChild(root->right->left, NodeVal, true);
     
  NodeVal.i=8;
  createNodeChild(root->right->right, NodeVal, false);
  createNodeChild(root->right->right, NodeVal, true);

  assert(getTreeSize(root)==15);


  

}

int mainStack(){
     struct Node* root=newNode(root, i);
     union Value NodeVal;

     NodeVal.i=1;
     setNodeValue(root, NodeVal);

     pushStack(root, NodeVal);
     pushStack(root, NodeVal);
     pushStack(root, NodeVal);
     assert(sizeStack(root)==4);
     /*
     NodeVal.i++; createNodeChild(root,  NodeVal, false);
     NodeVal.i++; createNodeChild(root->right,  NodeVal, false);
     NodeVal.i++; createNodeChild(root->right->right,  NodeVal, false);
     NodeVal.i++; createNodeChild(root->right->right->right,  NodeVal, false);
     */

     printStack(root);
     //printTree(root);
     

     return -1;
}

int main(){
     mainTree();
//     mainStack();
     
}
