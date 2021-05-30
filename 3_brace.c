#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char dat;
	struct Node *next;
}Node;

typedef struct 
{
	Node *head;
	int size;
}List;

void init(List* lst)
{
	lst->head = NULL;
	lst->size=0;
}

void ins(List* lst, char data)
{
	//вставка нового элемента в список
	Node  *newN = (Node*) malloc(sizeof(Node));
	Node *current = lst->head;

	newN->dat = data;           
	newN->next = NULL;
	
	if(current == NULL)
	{
		lst->head = newN;
		lst->size++;	
	}
	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = newN;
		lst->size++;
	}
}
Node* rm(List* lst, char data)
{
	//удаление элемента из списка
	Node *current = lst->head;
	Node *parent = NULL;
	if(current==NULL)
		return NULL;
	while(current->next!=NULL && current->dat!=data)
	{
		parent=current;
		current = current->next;
	}
	if(current->dat!=data)
	{
		return NULL;
	}
	if(current==lst->head)
	{
		lst->head=current->next;
		lst->size--;
		return current;
	}
    parent->next=current->next;
	lst->size--;
	return current;
}


void printNode(Node* n)
{
	//печать элемента списка
	if(n==NULL)
	{
		printf("[] ");
		return;
	}
	printf("[%c] ",n->dat);
	           
}
void printList(List* lst)
{
	//печать всего списка
	Node* current=lst->head;
	if(current==NULL)
	{
		printNode(current);
	}
	else
	{
		do
		{
			printNode(current);
			current = current->next;
		} while(current!=NULL);
		printf("\nSize: %d\n",lst->size);
	}
}
List *copyList(List *lst)
{
	//копироваие списка
	List *clone = (List*)malloc(sizeof(List));
	Node *n;

	init(clone);
	for(n=lst->head; n!=NULL; n=n->next)
	{
		  ins(clone,n->dat);	
	}
	return clone;
}
int checkSortList(List *lst)
{
	//проверка списка на отсортированность
	Node *n;
    int ascending=0;
	int descending = 0;
	char tmp;
	n=lst->head;
	tmp=n->dat;
	
	for(n=lst->head; n!=NULL; n=n->next)
	{
		if(tmp > n->dat)	descending++;
		else if (tmp < n->dat)	ascending++;   	
		tmp=n->dat;
	}
	if ((ascending!=0)&&(descending!=0) )
	{
		printf("Список не отсортирован\n");
		return -1;
	}
	else if ((ascending!=0)&&(descending==0)) 	
	{
		printf("Список отсортирован по возрастанию\n");
		return 0;
	}
	else if ((ascending==0)&&(descending!=0))
	{
		printf("Список отсортирован по убыванию\n");
		return 0;
	}
	else if ((ascending==0)&&(descending==0) )	
	{
		printf("Список состоит из равных элементов\n");
		return 0;
	}
}

void freeNode(Node *n)
{
	//освобождение памяти элемента
	if(n->next)
		freeNode(n->next);
	free(n);
}

void freeList(List *lst)
{
    //осовобождение памяти списка
    while(lst->size)
	{
		Node *tmp=lst->head;
	    lst->head=tmp->next;
		free(tmp);
		lst->size--;
	}
	
	
}

int checkBracket()
{
//функция которая определяет, является ли введенная скобочная последовательность правильной
	char ch[100], *p;
	int i=0,ret;
	List *lst = (List*)malloc(sizeof(List));
    Node *n;
	init(lst);
	p=ch;
	printf("Введите скобочную последовательность:\n");

	while(( *p++=getchar())!='\n');
	*p = '\0';
	
    i=0;
	
	while(ch[i]!='\0')
	{
		switch(ch[i])
		{
		case '(': 
			n=rm(lst,')');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);
		break;
		
		case '{': 
			n=rm(lst,'}');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);
		break;
		case '[':
			n=rm(lst,']');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);
		
		break;
		case  ')':
			n=rm(lst,'(');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);
		
		break;
	
		case '}':
			   
			n=rm(lst,'{');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);
		break;
		case ']':
			n=rm(lst,'[');
			if(n==NULL)	ins(lst,ch[i]);	
			else free(n);			
		break;
		
		default:
		break;
		}
		
	i++;	
	}
	if (lst->size>0)    
	{
		printf("Последовательность не правильная\n");	
		ret= -1;
	}
	else    
	{
		printf("Последовательность правильная\n");	
		ret =0;
	
	}
	freeList(lst);	    
    return ret;
}
int main(int argc, const char** argv)
{
	
	checkBracket();
	List *lst = (List*)malloc(sizeof(List));
	List *lst2;
	init(lst);

  	ins(lst,'a');	
  	ins(lst,'b');	
  	ins(lst,'c');	
  	ins(lst,'d');	
  	ins(lst,'e');	
    printList(lst);
	lst2 = copyList(lst);
  	ins(lst,'a');	
    printList(lst2);
    printList(lst);
	checkSortList(lst2);
	checkSortList(lst);
	freeList(lst);	    
	freeList(lst2);	    
	
	
	return 0;
	
	
}

