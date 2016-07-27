#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int* primefactors(int n);
//void parser(char*, char**);

int* primefactors(int n)
{
	int temp[256];
	char *temp1;
	char a[256];
	temp1 = a;
	//strcpy(temp1, temp);
	int j = 0;
	while(n%2==0)
	{
		//printf("%d x ", 2); 
		temp[j] =  2;
		j++;
		n /= 2;
	}

	int i;
	for(i = 3; i <= (int)  sqrt( (n * 1.0 )); i+= 2)
	{
		while(n%i==0)
		{
		//	printf("%d x ", i);
                	temp[j] =  i;
                	j++;
                	n/=i;
		}
	}

	if(n > 2)
	{
		temp[j] =  n;
		temp[j+1] = '\0';
		//printf("%d", n);
	}
	else
	{
		temp[j] = '\0';	
	}

	//for(i = 0; temp[i]; i++)
	//{
	//	printf("%d\n ", temp[i]);
	//}
	//printf("String: %s", temp);
	//temp1 = temp;
	
	return temp;
}

/*void parser(char* buffer, char* args[])
{
	while(*buffer != 0)
	{
		while(*buffer == ' ' || *buffer == '\t' || *buffer == '\n')
		{
			*buffer++ = '\0';
		}
		*args++ = buffer;
		while(*buffer != '\0' && *buffer != '\t' && *buffer != '\n')
		{
			buffer++;
		}
	}
		*args = 0;
}
*/
int main(int argc, char* argv[])
{
	//char *temp;
	//temp = primefactors(atoi(argv[1]));

	printf("Prime Factorization of %d is ", atoi(argv[1]));
	//int i;
	//for(i = 0; *temp[i+1]; i++)
	//{
	//	printf("%c x", *temp[i]));
	//}
	int *a = primefactors(atoi(argv[1]));
	int i;
	for(; *(a + 1) != '\0'; a++)
	{
		printf("%d x ", *a);
	}
	printf("%d\n", *a);
	//printf("String: %s\n", primefactors(atoi(argv[1])));

	return 0;
}
