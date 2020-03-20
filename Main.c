#include<stdlib.h>
#include<stdio.h>
#include "Tree.h"




int main(){
     struct Node* root=newNode(root, 1, i);
     union Value NodeVal;
     NodeVal.i=1;
     setNodeValue(root, NodeVal);

     NodeVal.i=2;
     createNodeChild(root, 2, NodeVal, false);
     createNodeChild(root, 3, NodeVal, true);

     NodeVal.i=3;
     createNodeChild(root->left, 4, NodeVal, false);
     createNodeChild(root->left, 5, NodeVal, true);

     NodeVal.i=4;
     createNodeChild(root->right, 6, NodeVal, false);
     createNodeChild(root->right, 7, NodeVal, true);

     NodeVal.i=5;
     createNodeChild(root->left->left,8, NodeVal, false);
     createNodeChild(root->left->left,9, NodeVal, true);
     
     NodeVal.i=6;
     createNodeChild(root->left->right,10, NodeVal, false);
     createNodeChild(root->left->right,11, NodeVal, true);

     NodeVal.i=7;
     createNodeChild(root->right->left,12, NodeVal, false);
     createNodeChild(root->right->left,13, NodeVal, true);
     
     NodeVal.i=8;
     createNodeChild(root->right->right,14, NodeVal, false);
     createNodeChild(root->right->right,15, NodeVal, true);
     /*
     */


     printTree(root);
  
  

}
