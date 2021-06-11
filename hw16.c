#include <stdio.h>
#include <stdlib.h>

#define encrypt  1
#define decrypt -1

int *createKey(char *key, int size)
{
   int i=0,j=0, indx=0;
   int  *intKey = (int*) calloc(sizeof(int), size);
   for (i=0; i<size; i++)
   {
   	 indx=0;
	 for (j=0;j<size;j++)
	 {
	 	if ((key[i]>key[j]) ||
		    ((key[i]==key[j])&&(j<i)))
			indx++;
	 }
	 intKey[i]=indx;   	
   }
   return intKey;	
}


int getSize(char *in)
{
	int size=0;
	while( in[size] != '\0')
		size++;
	return size;
}


char* createUnStr(char *in, int *key, int row, int size, int type)
{
    int i,j,k, col=(size)/row;
	char** array;
    char    *str;
    
	if (type==encrypt)
    {
		i=row;
		row=col;
		col=i;
	}

	array = (char**) calloc(sizeof(char*), col);
    str = (char*) calloc(sizeof(char), size);
    
	for (i = 0; i < col; ++i)
        *(array + i) = (char*) calloc(sizeof(char), row);

	k=0;    	             
	for ( i = 0; i < col; ++i)
    {
        for (j = 0; j < row; ++j)
        {
			if (type==encrypt)
	            *((*(array + i)) + key[j])=in[k];            
			else
            	*((*(array + i)) + j)=in[k];
			k++;
        }		
    }
 			
	k=0;
	for ( j = 0; j < row ; ++j)
    {
        for (i = 0; i < col; ++i)
        {
			if (type==encrypt)
                str[k] = *((*(array + i)) + j);
			else	
				str[k] = *((*(array + key[i])) + j);
			k++;
        }
		
    }

	str[size]='\0';	
	return str;

} 


char *swapCode(char *in, char* key, int type)
{   

	int keySize=0, size=0;
	char *str;
	int *keyInt;

    keySize=getSize(key);
	size= getSize(in);
	
	keyInt= createKey( key,  keySize);
	
	str=createUnStr(in, keyInt, size/keySize,  size,type);
    /*
	if (type==encrypt)
		str=createStr(in, keyInt, size/keySize,  size);
	else
		str=createDeStr(in, keyInt, size/keySize,  size);
   */
   free(keyInt);
  return str;
}



char* Caesar(char *in, int key, int type)
{
	
	char *p = in;
	int i=0;
	char ch;
	char *str;
	
	key *= type;
	
	while( *p != '\0')
	{
		i++;
		p++;
	}
	
	p = p - i;
	str = (char*) calloc((i+1) , (sizeof(char)));
	i = 0;
	while( *p != '\0')
	{  
		if ((*p >= 'a') && (*p <= 'z'))
		{
			ch = *p+key;
			if (ch >'z')
		  		ch = 'a'+ (ch - 'z') - 1;
		  
			if (ch < 'a')
				ch = 'z'- ('a' - ch) + 1;
			str[i++] = ch;				
			
		}
		p++;
		
	}	        	
	return str;
}

int main(int argc, const char** argv)
{
	char str[100], *p, *str1,*str2;
	
	p=str;
	
	printf("input a string:\n");                 
	while(( *p++ = getchar())!='\n');
	*p = '\0';
	printf("\nCaesar encryption: \n");                 
    
	str1 = Caesar(str, 5, encrypt);	
	printf("encrypted string:  %s \n", str1);                 
	
	str2 = Caesar(str1, 5, decrypt);	
	printf("decrypted string:  %s \n", str2);                 
	free(str1);	
	free(str2);

	printf("Permutation ecryption: \n");                 
                        
   str1= swapCode(str, "cba", encrypt);
   printf("encrypted string:  %s \n", str1);                 
  
   str2= swapCode(str1, "cba", decrypt);
   printf("decrypted string:  %s \n", str2);                 
   free(str1);	
   free(str2);
	
	return 0;
}

/*

char* createStr(char *in, int *key, int row, int size)
{
    int i,j,k, col=(size)/row;

	char** array = (char**) calloc(sizeof(char*), row);
    char    *str = (char*) calloc(sizeof(char), size);
    
	for (i = 0; i < row; ++i)
        *(array + i) = (char*) calloc(sizeof(char), col);

	k=0;
    	             
	for ( i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            *((*(array + i)) + key[j])=in[k];
			k++;
        }
					
	k=0;
	for ( j = 0; j < col; ++j)
        for (i = 0; i < row; ++i)
        {
            str[k] = *((*(array + i)) + j);
			k++;
        }
	str[size]='\0';
	return str;

}

char* createDeStr(char *in, int *key, int row, int size)
{
    int i,j,k, col=(size)/row;

	char** array = (char**) calloc(sizeof(char*), col);
    char    *str = (char*) calloc(sizeof(char), size);
    
	for (i = 0; i < col; ++i)
        *(array + i) = (char*) calloc(sizeof(char), row);


	k=0;    	             
	for ( i = 0; i < col; ++i)
    {
        for (j = 0; j < row; ++j)
        {
            *((*(array + i)) + j)=in[k];
			k++;
        }		
    }
 			
	k=0;
	for ( j = 0; j < row ; ++j)
    {
        for (i = 0; i < col; ++i)
        {
			str[k] = *((*(array + key[i])) + j);
			k++;
        }
		
    }
	str[size]='\0';
	
	return str;

}


*/
	
