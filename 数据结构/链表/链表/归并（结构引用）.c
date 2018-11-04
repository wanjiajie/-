//这种方法与上一种方法非常相似。这种方法避免使用虚拟节点(dummy node)，而是使用一个指向指针的指针，struct node** lastPtrRef，
//这个指针指向结果链表的最后一个节点。
//在这个方法中，所有由虚拟节点完成的工作都有lastPtrRef完成。
/* method2 Using local References */
struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node* result = NULL;

	/*point to the last result pointer */
	struct node** lastPtrRef = &result;

	while (1)
	{
		if (a == NULL)
		{
			*lastPtrRef = b;
			break;
		}
		else if (b == NULL)
		{
			*lastPtrRef = a;
			break;
		}
		if (a->data <= b->data)
		{
			MoveNode(lastPtrRef, &a);
		}
		else
		{
			MoveNode(lastPtrRef, &b);
		}
		/*tricky:advance to point to the next ".next" field */
		lastPtrRef = &((*lastPtrRef)->next);
	}
	return (result);
}
