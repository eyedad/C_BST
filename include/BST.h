#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BST_H
#define BST_H

typedef struct Data_ {
  int key;
  char *data;
} Data;

int order(char *str);

typedef struct BST_ {
  Data data;
  struct BST_ *left, *right;
} BST;

BST *createNewNode(Data data);
BST *insert(BST *root, Data data);
BST *search(BST *root, int key);
BST *findMin(BST *root);
BST *findMax(BST *root);
BST *delete(BST *root, int key);
int maxDepth(BST *root);
void collapseTree(BST *root);
#endif