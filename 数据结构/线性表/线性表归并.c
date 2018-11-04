#include<stdio.h>
struct LinerList
{
	int *list;
	int size;
	int MAXSIZE;
};
int main()
{
	int list1[15] = { 2,5,7,8,10,14,19,22,25,30 };
	int list2[15] = { 3,5,8,9,11,18,22,28,30,32,35 };
	int list3[30];
	struct LinerList L1 = { list1,10,15 };
	struct LinerList L2 = { list2,11,15 };
	struct LinerList L3 = { list3,0,30 };
	int i, j, k;
	for (i = j = k = 0; k < L3.MAXSIZE&&i < L1.size&&j < L2.size; k++)
	{
		if (L1.list[i] > L2.list[j])
			L3.list[k] = L2.list[j++];
		else if (L1.list[i] == L2.list[j])
		{
			L3.list[k] = L1.list[i++];
			j++;
		}
		else L3.list[k] = L1.list[i++];
	}
	while (k < L3.MAXSIZE&&i < L1.size)
		L3.list[k++] = L1.list[i++];
	while (k < L3.MAXSIZE&&j < L2.size)
		L3.list[k++] = L2.list[j++];
	L3.size = k;
	printf(" 合并后的数组长度是【%d】\n各元素如下：\n", L3.size);
	for (k = 0; k < L3.size; k++)
		printf("%4d", L3.list[k]);
	printf("\n");
	return 0;

}
