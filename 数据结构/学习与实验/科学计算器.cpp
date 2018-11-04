#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define MAXSIZE 200
void Translate(const char str[], char exp[])
double CompValue(const char*exp);
double CharToDouble(const char*str)
void Getstr(char*str)
int main()
{
	char str[MAXSIZE], exp[MAXSIZE];
	double answer;
	Getstr(str);
	puts(str);
	Translate(str, exp);
	puts(exp);
	answer = CompValue(exp);
	printf("%s=%lf", str, answer);
	return 0;
}
void Translate(const char str[], char exp[])
{
	char stack[MAXSIZE];
	int i = 0; k = 0; top = -1;
	while (str[i] != '#')
	{
		if (str[i] == '(')
			stack[++top] = str[i++];
		else if (str[i] == ')')
		{
			while (top >= 0 && stack[top] != ')')
			{
				exp[k++] = stack[top--];
			}
			if (top < 0)
			{
				puts("'('²»Æ¥Åä\n");
				exp[k++] = '\0';
				return;
			}
			top--;
			i++;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (top >= 0 && stack[top] != ')')
			{
				exp[k++] = stack[top--];
			}
			stack[++top] = str[i++];
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (top >= 0 && stack[top] != ')')
			{
				exp[k++] = stack[top--];
			}
			stack[++top] = str[i++];
		}
		else
		{
			while ((str[i] >= '0'&&str[i] <= '9') || str[i] == '.')
			{
				exp[k++] = str[i++];
			}
			exp[k++] = '#';
		}
	}
	while (top >= 0)
	{
		if (stack[top] == '(')
		{
			puts("'('²»Æ¥Åä\n");
			exp[k++] = '\0';
			return;
		}
		exp[k++] = stack[top--];
	}
	exp[k++] = '\0';
    
}

double CharToDouble(const char*str)
{
	double sumint = 0, sumdec = 0, e = 1;
	int i = 0;
	while (str[i] >= '0'&&str[i] <= '9')
	{
		sumint = sumint * 10 + str[i++] - '0';
	}
	if (str[i] == '.')
	{
		while (str[i++] != '\0')
		{
			sundec = sumdec * 10 + str[i] - '0';
			e *= 10;
		}
	}
	return sumint + sumdec / e;
}


double CompValue(const char*exp)
{
	char tempstr[MAXSIZE];
	double stack[MAXSIZE];
	int i = 0, k = 0, top = -1;
	while (exp[i] != '0')
	{
		if (exp[i] >= '0'&&exp[i] <= '9')
		{
			while (exp[i] != '#')
			{
			    tempstr[k++] = exp[i++];
			}
			tempstr[k] = '\0';
			stack[top++] = CharToDouble(tempstr);
			i++;
		}
		else {
			switch (exp[i++])
			{
			    case'+':stack[top - 1] += stack[top];
					break;
				case'-':stack[top - 1] += stack[top];
					break;
				case'*':stack[top - 1] += stack[top];
					break;
				case'/':if(stack[top]!=0)  stack[top - 1] += stack[top];
					else
				    {			
					    puts("³ýÁã´íÎó\n");
						return 0;
				    }
					break;
			}
			top--;
		}
	}
	return stack[top];
}

void Getstr(char*str)
{
	while ((str[i] = getchar()) != EOF)
	{
		if (str[i] == '')  i--;
		i++;
	}
	str[i++] = '#';
	str[i] = '\0';
}


