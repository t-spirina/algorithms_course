#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 10
typedef struct
{
	int pr;
	int dat;
}Node;

Node* arr[SIZE];
int head;
int tail;
int items;
void init()
{
int i;
	for(i=0; i<SIZE; i++)
		arr[i]=NULL;
	head=0;
	tail=0;
	items=0;
}

void ins(int pr, int dat)
{
	Node *node= (Node*) (malloc(sizeof(Node)));
	node->dat = dat;
	node->pr = pr;
	if(items==SIZE)
	{
		printf("Queue is full\n");
		return;
	}
	else
	{
		arr[tail++%SIZE]=node;
		items++;
	}	
}

Node* rem()
{
	if(items==0)
	{
		return NULL;
	}
	else
	{
        int i=0;
		int flag=0;
		Node* tmp= arr[0];
		flag=0;
		for(i=1;i<items;i++)
		{
			if(arr[i]->pr > tmp->pr)
			{
				tmp=arr[i];
				flag=i;
			}
		}		
		
		i=flag;
		//От флага до хвоста, свигаю все элеменеты влево
		while (i<=items)
		{
			arr[i]=arr[i+1];
			i++;
			
		}
		arr[tail]=NULL;
		free(arr[tail]);		
		items--;
		tail--;
		return tmp;
	}
}

void printQueue()
{
	int i;
	printf("[");
	for (i=0;i<SIZE;++i)
	{
		if(arr[i]==NULL)
			printf("[*,*] ");
		else
			printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
			
	}
	printf(" ]\n");
	
}

int main(int argc, const char** argv)
{
	int i=0;	
	Node* n;
	init();

	ins(3,1);
	ins(2,2);  
	ins(3,3);
	ins(1,4);
	ins(3,5);  
	ins(2,6);
	ins(1,7);  
    printQueue();
printf("del:\n");
    for(i=0;i<5;i++)
	{
		n=rem();
	    printQueue();
		
	}        
printf("ins:\n");
	
	ins(2,2);  
	ins(3,3);
	ins(3,5);  
	ins(2,6);
	ins(1,7);  
    printQueue();

	printf("del:\n");
	       
    for(i=0;i<5;i++)
	{
		n=rem();
	    printQueue();
	}        
    printf("\n\n");
	  
	return 0;
}
