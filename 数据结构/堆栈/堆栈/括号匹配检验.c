


//"期待紧迫度“：算法中设置一个栈，每读入一个括号；若是右括号，
//则使置于栈顶的最紧迫的期待得以消解；
//若是左括号，则作为新的更紧迫的期待 压入栈中，自然使原有的
// 在栈中所有未消解的期待的急迫性都 降了一级。 

#include <stdio.h>
#include <stdlib.h>
#define STACKINCREAMENT 10
#define STACK_INIT_SIZE 100
#define OVERFLOW -1
#define OK 1
#define ERROR 0
typedef int status;
typedef char SElemtype;
typedef struct
{
	SElemtype *base;
	SElemtype *top;
	int stacksize;
}sqstack;

//初始化栈
status Initstack(sqstack *s)
{
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

//压栈
status push(sqstack *s, SElemtype e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (SElemtype *)realloc(s->base, (s->stacksize + STACKINCREAMENT) * sizeof(SElemtype));
		if (!s->base)
			exit(OVERFLOW);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREAMENT;
	}
	*s->top++ = e;
	return OK;
}

//出栈
status pop(sqstack *s, SElemtype *e)
{
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

//判断是否为空栈
status stackempty(sqstack *s)
{
	if (s->top == s->base)
		return OK;
	return ERROR;
}


//括号匹配算法
status Parenthesismatch(sqstack *s, char *str)
{
	int i = 0, flag = 0;
	SElemtype e;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '(':
			push(s, str[i]);
			break;
		case '[':
			push(s, str[i]);
			break;
		case '{':
			push(s, str[i]);
			break;
		case ')':
		{
			pop(s, &e);
			if (e != '(')
				flag = 1;
		}
		break;
		case ']':
		{
			pop(s, &e);
			if (e != '[')
				flag = 1;
		}
		break;
		case '}':
		{
			pop(s, &e);
			if (e != '{')
				flag = 1;
		}
		break;
		default:
			break;
		}
		if (flag)
			break;
		i++;
	}

	if (!flag && stackempty(s))
		printf("括号匹配成功!\n");
	else
		printf("括号匹配失败!\n");
	return OK;
}

int main()
{
	char str[100];
	sqstack s;
	Initstack(&s);
	printf("请输入字符串:\n");
	scanf("%s", str);
	Parenthesismatch(&s, str);
	return 0;
}

