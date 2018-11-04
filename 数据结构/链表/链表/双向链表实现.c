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

// 创建一个链表 成功返回该链表的指针 否则返回NULL
LinkedList* Create(void)
{
	// 创建一个新节点
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	// 创建不成功，返回NULL
	if (!list) return NULL;

	list->head = NULL;
	list->tail = NULL;
	list->cur = NULL;
	list->size = 0;

	// 初始化成功后，返回list
	return list;
}

// 将元素添加到链表的末尾，成功返回链表的size，失败返回-1
int AddBack(LinkedList* list, void* data)
{
	// 创建一个新节点，创建不成功的话，返回-1
	Node* node = (Node *)malloc(sizeof(Node));
	if (!node) return -1;

	// 为节点的数据域赋值
	node->data = data;
	// 如果为链表的末尾
	if (list->tail)
	{
		list->tail->next = node;         // 把新节点赋给链表末尾的下一个
		node->prev = list->tail;   // 新节点的前一个等于之前的末节点
		node->next = NULL;         // 新节点为末节点，把它下一个指向NULL
	}
	else // 如果不为末尾，其实就是空链表
	{
		node->next = NULL;         // 新节点的下一个为NULL
		node->prev = NULL;         // 新节点的前一个为NULL
		list->head = node;         // 链表的头为新节点node
	}
	list->tail = node;                   // 链表的末尾指向node

	return ++list->size;                 // 返回链表的size
}

// 将元素添加到链表前端，成功返回非0，否则返回0
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

// 将元素从末端移除并返回该元素，如果链表为空则返回NULL
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

// 将元素从前端移除并返回该元素，如果链表为空则返回NULL
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

/* 如果当前链表为空则返回非0，否则返回0 */
int IsEmpty(LinkedList* list)
{
	return list->size == 0;
}

/* 获得链表的大小（元素总个数） */
int Size(LinkedList* list)
{
	return list->size;
}

/* 将当前位置移动到链表的开始 */
void Begin(LinkedList* list)
{
	list->cur = list->head;
}

/* 将当前位置移动到链表的最后 */
void End(LinkedList* list)
{
	list->cur = list->tail;
}
/* 将当前位置向后移动一个位置 */
void MoveNext(LinkedList* list)
{
	list->cur = list->cur->next;
}

/* 将当前位置向后移动一个位置 */
void MovePrev(LinkedList* list)
{
	list->cur = list->cur->prev;
}

/* 清空链表中所有元素 */
void Clear(LinkedList* list)
{
	while (RemoveBack(list));
}

/* 销毁一个链表 */
void Destroy(LinkedList* list)
{
	Clear(list);
	free(list);
}

/* 如果当前位置之后还有元素则返回非0，否则返回0 */
int HasNext(LinkedList* list)
{
	if (!list->cur) return 0;
	if (list->cur == list->tail) return 1;
	return list->cur->next != NULL;
}

/* 如果当前位置之前还有元素则返回非0，否则返回0 */
int HasPrev(LinkedList* list)
{
	if (!list->cur) return 0;
	if (list->cur == list->head) return 1;
	return list->cur->prev != NULL;
}

/* 返回当前位置的元素 */
void* Current(LinkedList* list)
{
	return list->cur->data;
}



// 正向打印链表
void Traverse(LinkedList* list)
{
	for (Begin(list); HasNext(list); MoveNext(list))
		printf("%d ", *(int*)Current(list));
	putchar('\n');
}

// 反向打印链表
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

	printf("链表大小(SIZE): %d\n", Size(list));

	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	printf("添加array2[0]数\n");
	AddBack(list, &array2[0]);

	printf("链表大小(SIZE): %d\n", Size(list));
	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	printf("调用AddFront函数，添加array2[0]数\n");
	AddFront(list, &array2[1]);

	printf("链表大小(SIZE): %d\n", Size(list));
	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	printf("从末尾移除的元素是: %d\n", *(int *)RemoveBack(list));
	printf("链表大小(SIZE): %d\n", Size(list));
	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	printf("从开头移除的元素是: %d\n", *(int *)RemoveFront(list));
	printf("链表大小(SIZE): %d\n", Size(list));
	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	printf("清空链表，Clear(list)后\n");
	Clear(list);
	printf("链表大小(SIZE): %d\n", Size(list));

	for (i = 0; i < 10; i++)
	{
		AddFront(list, &array2[i]);
	}
	printf("正向打印链表:\n");
	Traverse(list);
	printf("反向打印链表:\n");
	RTraverse(list);

	Destroy(list);
	printf("销毁链表Destroy(list)\n");

	return 0;
}