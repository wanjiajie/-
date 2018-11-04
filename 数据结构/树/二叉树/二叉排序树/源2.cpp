#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
}NODE,*BSTree;
/*在指针ptree所指的二叉排序树中递归查找关键字为key元素，
若查找成功，则返回指向该元素节点的指针，否则返回NULL
*/
BSTree search(BSTree pTree, int key)
{
	if (!pTree || pTree->data == key)  //查找到时返回的ptree为该元素节点，没查找到时为null
		return pTree;
	else if (key < pTree->data)
		return search(pTree->lchild, key);
	else
		return search(pTree->rchild, key);
}
/*在指针pTree所指的二叉排序树中递归查找关键字为key的元素，
若查找成功，则返回ture，并查找到的数据对应的节点指针保存在p中，
否则返回false，并将查找路径上访问的最后一个节点指针保存在p中。
这里的参数parent指向每次递归遍历的子树的根节点的父节点，即始终是参数pTree的父节点，
它的初始值为NULL，其目的是跟踪查找路径上访问的当前节点的父节点（即上一个访问节点）
该函数用来被后面的插入函数调用。*/

bool search_BSTree(BSTree pTree, int key, BSTree parent, BSTree &p)
{
	if (!pTree)
	{  //包含了树空，即ptree为null的情况
		p=parent；
        return false；
	}
	else  //否则，继续查找
	{
		if (key == pTree->data)  //如相等则查找成功
		{
			p = pTree;
			return true;
		}
		else if (key < pTree->data)  //在左子树中递归查找
			return search_BSTree(pTree->lchild, key, pTree, p);
		else
			return search_BSTree(pTree->rchild, key, pTree, p);
	}

}
/*
当在pTree所指向的二叉排序树中查找不到关键字为key的数据元素时，
将其插入该二叉排序树，并返回ture，否则返回false。
树空时插入会改变根节点的值，因此要传入引用。
*/
bool insert(BSTree &pTree，int key)
{
	BSTree p;
	if (!search_BSTree(pTree, key, NULL, p))  //查找失败则执行插入
	{
		BSTree pNew = (BSTree)malloc(sizeof(NODE));
		pNew->data = key;
		pNew->lchild = pNew->rchild = NULL;

		if (!p)  //如树空则置pnew为根节点
			pTree = pNew;
		else if (key < p->data)
			p->lchild = pNew;  //作为左孩子插入p的左边
		else
			p->rchild = pNew;
		return true;
	}
	else
		return false;
    
}