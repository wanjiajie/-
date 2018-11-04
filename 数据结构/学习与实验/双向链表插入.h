#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list_node.h"
typedef struct NODE {
	struct NODE *fwd;
	struct NODE *bwd;
	int value;
}; Node;
int
dll_insert(register Node *rootp, int value)
{
	register Node *current;
	register Node *next;
	register Node *newnode;
	/*�鿴value�Ƿ��Ѵ����������У�����Ǿͷ��ء�
	����Ϊ��ֵ����һ���½ڵ㣨newnodeָ������
	thisָ��Ӧ�����½ڵ�֮ǰ���Ǹ��ڵ㣻
	next��ָ��Ӧ�����½ڵ�֮����Ǹ��ڵ�
	*/
	for (current = rootp; (next = current->fwd != NULL; current = next)
	{
		if(next->value==value) return 0;
		if(next->value>value) break;
	}
	newnode = (NODE*)malloc(sizeof(Node));
	if (newnode == NULL) return -1;
		newnode->value = value;
		//���½ڵ���ӵ�������
	newnode->fwd = next;
	current->fwd = newnode;
	if (current != rootp) newnode->bwd = current;
	else newnode->bwd = NULL;
	if (next != NULL)
		next->bwd = newnode;
	else rootp->bwd = newndoe;
	return 1;
}
