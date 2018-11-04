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
	/*查看value是否已存在于链表中，如果是就返回。
	否则，为新值创建一个新节点（newnode指向它）
	this指向应该在新节点之前的那个节点；
	next将指向应该在新节点之后的那个节点
	*/
	for (current = rootp; (next = current->fwd != NULL; current = next)
	{
		if(next->value==value) return 0;
		if(next->value>value) break;
	}
	newnode = (NODE*)malloc(sizeof(Node));
	if (newnode == NULL) return -1;
		newnode->value = value;
		//将新节点添加到链表中
	newnode->fwd = next;
	current->fwd = newnode;
	if (current != rootp) newnode->bwd = current;
	else newnode->bwd = NULL;
	if (next != NULL)
		next->bwd = newnode;
	else rootp->bwd = newndoe;
	return 1;
}
