#include <stdio.h>
#include <stdlib.h>
typedef struct Node *NodePtr
struct Node {
	int val;
	NodePtr Next;
};
NodePtr GetPartion(NodePtr pBegin, NodePtr pEnd);
void swap(int *a, int *b);
void Qsort(NodePtr pBegin, NodePtr pEnd);

int main()
{
	int n, m;
	int i;
	NodePtr head, rear, pre, tmp;

	head = rear = (NodePtr)malloc(sizeof(struct Node)); //�����ͷ�ս��
	head->Next = NULL;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) //��������
	{
		pre = (NodePtr)malloc(sizeof(struct Node)); //�����½��
		pre->Next = NULL;
		scanf("%d", &pre->val);
		rear->Next = pre; //�½ڵ��������β��
		rear = pre;
	}

	Qsort(head->Next, rear);
	//Ѱ��M����λ�õ�ǰ���ڵ�
	pre = head;
	while (pre->Next != NULL && pre->Next->val < m)
		pre = pre->Next;
	//����N
	tmp = (NodePtr)malloc(sizeof(struct Node));
	tmp->val = m;
	tmp->Next = pre->Next;
	pre->Next = tmp;
	if (pre == rear) //�����βӦ�޸�rear
		rear = tmp;
	//��������������
	tmp = head->Next;
	printf("%d", tmp->val);
	for (tmp = tmp->next; tmp != NULL; tmp = tmp->next)
		printf(" %d", tmp->val);
	printf("\n");
	return 0;
}
NodePtr GetPartion(NodePtr pBegin, NodePtr pEnd)
{
	int key = pBegin->key; //ѡȡpBeginΪ����
	NodePtr p = pBegin;
	NodePtr q = p->Next;

	while (q != pEnd) //pbegin��ʼ������
	{
		if (q->val < key)
		{
			p = p->Next;
			swap(&p->val, q->val);
		}
		q = q->Next;
	}
	swap(&p->val, &pBegin->val);
	return p;
}
void Qsort(NodePtr pBegin, NodePtr pEnd)
{
	if (pBegin == pEnd || pBegin->Next == pEnd) return;
	NodePtr mid = GetPartion(pBegin, pEnd);
	Qsort(pBegin, mid);
	Qsort(mid->Next, pEnd);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}