#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define  true 1==1
#define  false 1!=1

typedef int boolean;

typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data);
void printTree(TreeNode *root);
TreeNode* getSuccessor (TreeNode *node);
boolean delete(TreeNode *root, int key);
//void preOrdeTravers (TreeNode *root);
//void inOrdeTravers (TreeNode *root);
//void postOrdeTravers (TreeNode *root);
int getHeight(TreeNode *root);
boolean isbalancedTree(TreeNode *root);
void delTree (TreeNode *root);
int treeFactory(int treeNum, int nodeNum);
int binsearch(TreeNode *root, int val);

