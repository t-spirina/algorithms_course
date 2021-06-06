/*
 *   Author: spirina tatyana
 *   vedit plus 5.16 os QNX 4.25
 */
#include "tree.h"  
//#define MAX(a,b) ((a)>=(b))?(a):(b)

int MAX(int a, int b)
{
	if(a>=b) return a;
	return b;
}

TreeNode* treeInsert(TreeNode *t, int data)
{
    TreeNode *newNode;
	TreeNode *current = t;
	TreeNode *parent = t;
             
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	         
	if(t==NULL)
	{
		t=newNode;
	}
	else
	{
		while(current->key!=data)
		{
			parent = current;
			if(current->key > data)
			{
				current = current->left;
				
				if(current==NULL)
				{
					parent->left=newNode;
					return t;
				}
			}
			else
			{
				current = current->right;
				if(current==NULL)
				{
					parent->right=newNode;
					return t;
				}
			}
		}
	}
	return t;
}

void printTree(TreeNode *root)
{
	if (root)
	{
		printf("%d",root->key);
		if(root->left || root->right)
		{
			printf("(");
			if(root->left)
				printTree(root->left);
			else
				printf("NULL");
			
			printf(", ");
			    
			if(root->right)
				printTree(root->right);			
			else
				printf("NULL");
			printf(")");
		}	
	}
	
}

TreeNode* getSuccessor (TreeNode *node)
{
	TreeNode *current = node->right;
	TreeNode *parent = node;
	TreeNode *s = node;
	
	while(current!=NULL)
	{
		parent = s;
		s = current;
		current = current->left;
	}
	if( s!=node->right)
	{
		parent->left = s->right;
		s->right = node->right;
	}
	return s;
}


boolean delete(TreeNode *root, int key)
{
	TreeNode *current = root;
	TreeNode *parent = root;
	boolean IsLeftChild = true;

	while(current->key != key)
	{
		parent=current;
		if(key < current->key)
		{  
			current=current->left;
			IsLeftChild = true;
		}
		else
		{
			current=current->right;
			IsLeftChild = false;
		}
		if (current==NULL)
			return false;		
	}	
	
	if(current->left == NULL && current->right == NULL)
	{
		
		if(current == root)
			root = NULL;                       
		else if(IsLeftChild) 
			parent->left = NULL;
		else 
			parent->right = NULL;			
	}	

	else if (current->right == NULL)
	{
		if(IsLeftChild)
			parent->left = current->left;
		else
			parent->right = current->left;
			
	}
	else if (current->left == NULL)
	{
		if(IsLeftChild)
			parent->left = current->right;
		else
			parent->right = current->right;
		
	}
	
	else
	{   
		TreeNode *successor = getSuccessor(current);
		if (current == root)
			root =successor;
		else if (IsLeftChild)
			parent->left = successor;
		else
			parent->right = successor;
		successor->left = current->left;
	}	

	free(current);			
	return true;		
}

int getHeight(TreeNode *root)
{
//определить высоту дерева
	if(root==NULL)
		return 0;
	return (1 + MAX(getHeight(root->left),getHeight(root->right)));
} 
boolean isbalancedTree(TreeNode *root)
{
	int leftHeight=0;
	int rightHeight=0;
	
	
    leftHeight=1+getHeight(root->left);
	rightHeight=1+getHeight(root->right);
	
	if (abs(rightHeight-leftHeight)>1)
		return false;
	
	return true;
	
}
void delTree (TreeNode *root)
{

	if(root!=NULL)
	{
		delTree(root->left);
		delTree(root->right);
		free(root);
	}
}

int treeFactory(int treeNum, int nodeNum)
{
//функция создаст treeNum деревьев по nodeNum узлов 
//и заполнит узлы случайными целочисленными значениями;
//на выходе получим процент сбалансированных деревьев
	int i=0;
	int blns=0;
	for(i=0;i<treeNum;i++)
	{
		int j=0;
		TreeNode *tree = NULL;	
		
		for(j=0;j<nodeNum;j++)
		{	
			tree=treeInsert(tree,(rand()%((i+1)*1000)));
		}
	
		if (isbalancedTree(tree))
			blns++; 
		 
		 delTree(tree);
	}
	
	return ((blns*100)/treeNum); 
   	  
}
int binsearch(TreeNode *root, int val)
{
    int i=0;
	if(root==NULL)
	{
   		return 0;
    }
	if(root->key==val)
	{
	 	return 1;
	}
	if(root->key>val)
		i=i+binsearch(root->left,val);
	else 
		i=i+binsearch(root->right,val);
    return i;
}

int main(int argc, const char** argv)
{
	
	int i=0;
	TreeNode *tree = NULL;
	tree=treeInsert(tree,10);
	            
	treeInsert(tree,8);
	treeInsert(tree,19);
	treeInsert(tree,5);
	treeInsert(tree,9);
	treeInsert(tree,16);
	treeInsert(tree,21);

	
	if (isbalancedTree(tree))
		printf("balansed\n");	
	else
		printf("dis-balansed\n");	
	
	treeInsert(tree,23);
	treeInsert(tree,25);
	treeInsert(tree,20);
	treeInsert(tree,22);	
	
	i=binsearch(tree,22);
	if(i>0)
	printf("22 - bingo! %d\n",i);	
	else
	printf("--22--  %d \n",i);	
	
	i=binsearch(tree,15) ;
	if(i>0)
		printf("15 - bingo! %d\n",i);	
	else
	printf("--15--  %d\n",i);	
	
	
	
    printTree(tree);
	printf("\n");	
    delTree(tree);
	
	printf("treeFactory= %d%%\n", treeFactory(50,10000));
	return 0;
}
