#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTag Node;
typedef struct LinkedListTag LinkedList;

struct NodeTag
{
	Node* prev;
	Node* next;
	void* data;
};

struct LinkedListTag
{
	Node* head;
	Node* tail;
	Node* cur;
	int size;
};

// ����һ������ �ɹ����ظ������ָ�� ���򷵻�NULL
LinkedList* Create(void)
{
	// ����һ���½ڵ�
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	// �������ɹ�������NULL
	if (!list) return NULL;

	list->head = NULL;
	list->tail = NULL;
	list->cur = NULL;
	list->size = 0;

	// ��ʼ���ɹ��󣬷���list
	return list;
}

// ��Ԫ����ӵ������ĩβ���ɹ����������size��ʧ�ܷ���-1
int AddBack(LinkedList* list, void* data)
{
	// ����һ���½ڵ㣬�������ɹ��Ļ�������-1
	Node* node = (Node *)malloc(sizeof(Node));
	if (!node) return -1;

	// Ϊ�ڵ��������ֵ
	node->data = data;
	// ���Ϊ�����ĩβ
	if (list->tail)
	{
		list->tail->next = node;         // ���½ڵ㸳������ĩβ����һ��
		node->prev = list->tail;   // �½ڵ��ǰһ������֮ǰ��ĩ�ڵ�
		node->next = NULL;         // �½ڵ�Ϊĩ�ڵ㣬������һ��ָ��NULL
	}
	else // �����Ϊĩβ����ʵ���ǿ�����
	{
		node->next = NULL;         // �½ڵ����һ��ΪNULL
		node->prev = NULL;         // �½ڵ��ǰһ��ΪNULL
		list->head = node;         // �����ͷΪ�½ڵ�node
	}
	list->tail = node;                   // �����ĩβָ��node

	return ++list->size;                 // ���������size
}

// ��Ԫ����ӵ�����ǰ�ˣ��ɹ����ط�0�����򷵻�0
int AddFront(LinkedList* list, void* data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if (!node) return 0;

	node->data = data;
	if (list->head)
	{
		list->head->prev = node;
		node->next = list->head;
		node->prev = NULL;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		list->tail = node;
	}
	list->head = node;

	return ++list->size;
}

// ��Ԫ�ش�ĩ���Ƴ������ظ�Ԫ�أ��������Ϊ���򷵻�NULL
void* RemoveBack(LinkedList* list)
{
	Node* temp;
	void* data;

	if (!list->size) return NULL;

	temp = list->tail;
	data = list->tail->data;

	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		list->cur = NULL;
	}
	else
	{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	--list->size;
	free(temp);
	return data;
}

// ��Ԫ�ش�ǰ���Ƴ������ظ�Ԫ�أ��������Ϊ���򷵻�NULL
void* RemoveFront(LinkedList* list)
{
	Node* temp;
	void* data;

	if (!list->size) return NULL;

	temp = list->head;
	data = list->head->data;

	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		list->cur = NULL;
	}
	else
	{
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	--list->size;
	free(temp);
	return data;
}

/* �����ǰ����Ϊ���򷵻ط�0�����򷵻�0 */
int IsEmpty(LinkedList* list)
{
	return list->size == 0;
}

/* �������Ĵ�С��Ԫ���ܸ����� */
int Size(LinkedList* list)
{
	return list->size;
}

/* ����ǰλ���ƶ�������Ŀ�ʼ */
void Begin(LinkedList* list)
{
	list->cur = list->head;
}

/* ����ǰλ���ƶ����������� */
void End(LinkedList* list)
{
	list->cur = list->tail;
}
/* ����ǰλ������ƶ�һ��λ�� */
void MoveNext(LinkedList* list)
{
	list->cur = list->cur->next;
}

/* ����ǰλ������ƶ�һ��λ�� */
void MovePrev(LinkedList* list)
{
	list->cur = list->cur->prev;
}

/* �������������Ԫ�� */
void Clear(LinkedList* list)
{
	while (RemoveBack(list));
}

/* ����һ������ */
void Destroy(LinkedList* list)
{
	Clear(list);
	free(list);
}

/* �����ǰλ��֮����Ԫ���򷵻ط�0�����򷵻�0 */
int HasNext(LinkedList* list)
{
	if (!list->cur) return 0;
	if (list->cur == list->tail) return 1;
	return list->cur->next != NULL;
}

/* �����ǰλ��֮ǰ����Ԫ���򷵻ط�0�����򷵻�0 */
int HasPrev(LinkedList* list)
{
	if (!list->cur) return 0;
	if (list->cur == list->head) return 1;
	return list->cur->prev != NULL;
}

/* ���ص�ǰλ�õ�Ԫ�� */
void* Current(LinkedList* list)
{
	return list->cur->data;
}



// �����ӡ����
void Traverse(LinkedList* list)
{
	for (Begin(list); HasNext(list); MoveNext(list))
		printf("%d ", *(int*)Current(list));
	putchar('\n');
}

// �����ӡ����
void RTraverse(LinkedList* list)
{
	for (End(list); HasPrev(list); MovePrev(list))
		printf("%d ", *(int*)Current(list));
	putchar('\n');
}


int main()
{
	int i;
	LinkedList* list = Create();

	int array1[10];
	int array2[10];

	for (i = 0; i < 10; i++)
	{
		array1[i] = i + 1;
		array2[i] = i + 100 + 1;
		AddBack(list, &array1[i]);
	}

	printf("�����С(SIZE): %d\n", Size(list));

	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	printf("���array2[0]��\n");
	AddBack(list, &array2[0]);

	printf("�����С(SIZE): %d\n", Size(list));
	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	printf("����AddFront���������array2[0]��\n");
	AddFront(list, &array2[1]);

	printf("�����С(SIZE): %d\n", Size(list));
	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	printf("��ĩβ�Ƴ���Ԫ����: %d\n", *(int *)RemoveBack(list));
	printf("�����С(SIZE): %d\n", Size(list));
	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	printf("�ӿ�ͷ�Ƴ���Ԫ����: %d\n", *(int *)RemoveFront(list));
	printf("�����С(SIZE): %d\n", Size(list));
	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	printf("�������Clear(list)��\n");
	Clear(list);
	printf("�����С(SIZE): %d\n", Size(list));

	for (i = 0; i < 10; i++)
	{
		AddFront(list, &array2[i]);
	}
	printf("�����ӡ����:\n");
	Traverse(list);
	printf("�����ӡ����:\n");
	RTraverse(list);

	Destroy(list);
	printf("��������Destroy(list)\n");

	return 0;
}