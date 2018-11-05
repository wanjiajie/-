#include <stdio.h>
#include <string.h> 
void reverse(char str[])
{	
	int l=0,r=strlen(str)-1;	
    char tmp;
	while (l < r)
	{
		tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++, r--;
	}
}
void add(char A[],char B[], char rst[])
{
	reverse(A);
	reverse(B);
	int i = 0;
	int tmp,carryover = 0;
	while (A[i] != '\0'&&B[i] != '\0')
	{
		tmp = A[i] - '0' + B[i] - '0';
		if (tmp > 9)
		{
			tmp = tmp - 10;
			rst[i] = tmp + '0';
			if (carryover) rst[i]++;
			carryover = 1;
		}
		else
		{
			rst[i] = tmp + '0';
			if (carryover) rst[i]++;
			carryover = 0;
		}
		i++;
	}
	if (B[i] == '\0' && A[i] != '\0')
	{
		rst[i] = A[i];
		if (carryover) rst[i]++;
		i++;
		while (A[i] != '\0')
		{
			rst[i] = A[i];
			i++;
		}
	}
	else if (A[i] == '\0'&&B[i] != '\0')
	{
		rst[i] = B[i];
		if (carryover) rst[i]++;
		i++;
		while (B[i] != '\0')
		{
			rst[i] = B[i];
			i++;
		}
	}
	else if (A[i] == '\0'&&B[i] == '\0'&&carryover)
	{
		rst[i] = 1;
		i++;
	}
	while (rst[i-1] == '0'&&i>1) i--;
	rst[i] = '\0';
	reverse(A);
	reverse(B);
	if(A!=rst) reverse(rst);
}
void multiply(char A[], char B[], char rst[])
{
	int i, j, k, carryover, tmp;
	char intermed[BUFSIZ];rst[0] = '0';rst[1]='\0';		
 	reverse(A);
	reverse(B);
	i = 0;
	carryover = 0;
	while (B[i] != '\0')
	{
		for (j = 0; j < strlen(A); j++)
		{
			tmp = (A[j] - '0')*(B[i] - '0');
			intermed[j] = '0' + tmp % 10;
			intermed[j] += carryover;
			carryover = 0;
			if (intermed[j] > '9')
			{
				intermed[j] -= 10;
				carryover++;
			}
			while (tmp > 9)
			{
				tmp -= 10;
				carryover++;
			}
		}
		if (carryover) intermed[j++] = '0' + carryover;
		carryover = 0;
		intermed[j] = '\0';
		reverse(intermed);
		for (k = 0; k < i; k++)	intermed[j+k] = '0'; //应用memset函数置0也可
		intermed[j+k] = '\0';
		add(rst, intermed, rst);
		i++;
	}
	reverse(A);
	reverse(B);
}
int main()
{
	char A[BUFSIZ],B[BUFSIZ],rst[BUFSIZ];
	scanf_s("%s", A,BUFSIZ);
	scanf_s("%s", B,BUFSIZ);
	multiply(A, B, rst);
	printf("%s",rst);
	return 0;
}

