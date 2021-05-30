#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 10
#define true 1==1
#define false 1!=1

typedef int boolean;
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
 
void decToBin(int decNum, Stack *stk)
{
	
	if (decNum==0) 
	{	
		return;		
	}
		
	if(decNum % 2 == 0)	
		push('0',stk);
	else
		push('1',stk);
	decToBin(decNum/2,stk);		
}

int main(int argc, const char** argv)
{
	
	Stack stk;
	int decNum;	

	printf("Введите положительное целое десятичное число: ");
	scanf("%d",&decNum);
    
	initStack(&stk);
	
	decToBin(decNum,&stk);

	printf("Его двоичное представление: \n");	           
    
	do
       printf("%c",pop(&stk));
	while(stk.cursor!=-1);
   
   printf("\n\n");
	  
	return 0;
}


