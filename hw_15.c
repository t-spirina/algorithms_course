#include <stdio.h>
#include <stdlib.h>

int hashFnc(char *in)
{
	char *p = in;
	int sum=0;
	while( *p != '\0')
	{  
	    sum+=(int)*p;
		p++;
	}	        
	return sum;
}

int* contCoins(int *coins,  int size, int sum)
{
	int i=0;
	int *coinsAmng=(int*)calloc(size, sizeof(int));
	
	for(i=0;i<size;i++)
	{
		coinsAmng[i]=sum/coins[i];
		sum=sum%coins[i];
	}
	
	return coinsAmng;
}
void printResult(int *coins, int *coinsAmng, int size)
{
	int i=0;
	int count=0;
	printf("coin | count \n");
	
	for(i=0;i<size;i++)
	{
		printf("%4d | %d\n",coins[i], coinsAmng[i]);
	    count+=coinsAmng[i];
	}
	printf("You need  %d coins for %d\n", count, size);
	
}

int main(int argc, const char** argv)
{
	char str[100], *p;
	int coins[5] = {50, 10, 5, 2, 1};
	int sum = 98;
	int* coinsAmng = contCoins(&coins,5,sum);
	
	p=str;
	
	printf("Input a string:\n");                 
	while(( *p++=getchar())!='\n');
	*p = '\0';
	printf("%d\n",hashFnc(str));                 
	
    printResult(&coins, coinsAmng, 5);
	free(coinsAmng);
		
	return 0;
}

	
