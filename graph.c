
#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 6
#define true 1==1
#define false 1!=1
typedef int boolean;

#define n  6
int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};

int visited[n] = { 0 };

typedef struct 
{
	T data[SIZE];
	int cursor ;
}Stack;


void initStack( Stack *stack)
{
	stack->cursor=-1;	
}

boolean push(T data, Stack *stack)
{
    if(stack->cursor < SIZE)
    {
		stack->cursor++;
        stack->data[stack->cursor] = data;
        return true;
    }
    else
    {
        printf("Stack overflow\n");
        return false;
    }
}

T pop(Stack *stk)
{
    T tmp;
	
	if(stk->cursor!=-1)
    {   
		tmp=stk->data[stk->cursor]; 
		stk->cursor--;
		return tmp;
	}
    else {

        printf("Stack is empty\n");
        return -1;
    }
}
 
void retsetArr()
{
    int i = 0;
    for (i = 0; i < n; ++i) 
	    visited[i]=0;
}

void depthTraversStk(int node) 
{
//обход в глубину с использованием стека
    int i = 0;
    Stack stk;
    initStack(&stk);
    retsetArr();
	push(node,&stk); 
	while (stk.cursor >-1)
	{
	    node=pop(&stk);
	    if( visited[node]!=1)
	    {
	        visited[node]=1;
	        printf("%d ",node);
	        for(i = (n-1); i >=0; --i)
	        {
	            if (matrix[node][i] == 1 && !visited[i])
		        	push(i,&stk); 
	        }
	    }
    }
}

int main(int argc, const char** argv)
{
	
	depthTraversStk(0);
    printf("\n\n");
	  
	return 0;
}




