//���ַ�������һ�ַ����ǳ����ơ����ַ�������ʹ������ڵ�(dummy node)������ʹ��һ��ָ��ָ���ָ�룬struct node** lastPtrRef��
//���ָ��ָ������������һ���ڵ㡣
//����������У�����������ڵ���ɵĹ�������lastPtrRef��ɡ�
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
