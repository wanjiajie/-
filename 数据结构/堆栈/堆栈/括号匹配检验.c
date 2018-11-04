


//"�ڴ����ȶȡ����㷨������һ��ջ��ÿ����һ�����ţ����������ţ�
//��ʹ����ջ��������ȵ��ڴ��������⣻
//���������ţ�����Ϊ�µĸ����ȵ��ڴ� ѹ��ջ�У���Ȼʹԭ�е�
// ��ջ������δ������ڴ��ļ����Զ� ����һ���� 

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

//��ʼ��ջ
status Initstack(sqstack *s)
{
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

//ѹջ
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

//��ջ
status pop(sqstack *s, SElemtype *e)
{
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

//�ж��Ƿ�Ϊ��ջ
status stackempty(sqstack *s)
{
	if (s->top == s->base)
		return OK;
	return ERROR;
}


//����ƥ���㷨
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
		printf("����ƥ��ɹ�!\n");
	else
		printf("����ƥ��ʧ��!\n");
	return OK;
}

int main()
{
	char str[100];
	sqstack s;
	Initstack(&s);
	printf("�������ַ���:\n");
	scanf("%s", str);
	Parenthesismatch(&s, str);
	return 0;
}

