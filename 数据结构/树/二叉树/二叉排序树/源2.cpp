#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
}NODE,*BSTree;
/*��ָ��ptree��ָ�Ķ����������еݹ���ҹؼ���ΪkeyԪ�أ�
�����ҳɹ����򷵻�ָ���Ԫ�ؽڵ��ָ�룬���򷵻�NULL
*/
BSTree search(BSTree pTree, int key)
{
	if (!pTree || pTree->data == key)  //���ҵ�ʱ���ص�ptreeΪ��Ԫ�ؽڵ㣬û���ҵ�ʱΪnull
		return pTree;
	else if (key < pTree->data)
		return search(pTree->lchild, key);
	else
		return search(pTree->rchild, key);
}
/*��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
�����ҳɹ����򷵻�ture�������ҵ������ݶ�Ӧ�Ľڵ�ָ�뱣����p�У�
���򷵻�false����������·���Ϸ��ʵ����һ���ڵ�ָ�뱣����p�С�
����Ĳ���parentָ��ÿ�εݹ�����������ĸ��ڵ�ĸ��ڵ㣬��ʼ���ǲ���pTree�ĸ��ڵ㣬
���ĳ�ʼֵΪNULL����Ŀ���Ǹ��ٲ���·���Ϸ��ʵĵ�ǰ�ڵ�ĸ��ڵ㣨����һ�����ʽڵ㣩
�ú�������������Ĳ��뺯�����á�*/

bool search_BSTree(BSTree pTree, int key, BSTree parent, BSTree &p)
{
	if (!pTree)
	{  //���������գ���ptreeΪnull�����
		p=parent��
        return false��
	}
	else  //���򣬼�������
	{
		if (key == pTree->data)  //���������ҳɹ�
		{
			p = pTree;
			return true;
		}
		else if (key < pTree->data)  //���������еݹ����
			return search_BSTree(pTree->lchild, key, pTree, p);
		else
			return search_BSTree(pTree->rchild, key, pTree, p);
	}

}
/*
����pTree��ָ��Ķ����������в��Ҳ����ؼ���Ϊkey������Ԫ��ʱ��
�������ö�����������������ture�����򷵻�false��
����ʱ�����ı���ڵ��ֵ�����Ҫ�������á�
*/
bool insert(BSTree &pTree��int key)
{
	BSTree p;
	if (!search_BSTree(pTree, key, NULL, p))  //����ʧ����ִ�в���
	{
		BSTree pNew = (BSTree)malloc(sizeof(NODE));
		pNew->data = key;
		pNew->lchild = pNew->rchild = NULL;

		if (!p)  //����������pnewΪ���ڵ�
			pTree = pNew;
		else if (key < p->data)
			p->lchild = pNew;  //��Ϊ���Ӳ���p�����
		else
			p->rchild = pNew;
		return true;
	}
	else
		return false;
    
}