//新建一low数组，low[i]表示长度为i的LIS结尾元素的最小值。
//对于一上升子列，显然其结尾元素越小，越有利于在后面
//接其他元素，也就越可能变得更长。因此，只需维护low数组
//对于每一个a[i]，若a[i]>low[当前最长lis长度],就把a[i]
//接到当前最长的lis后面，即low[++当前最长的lis长度]
//=a[i]，否则，就用a[i]更新low数组。具体方法是在low数组中
//找到第一个大于等于a[i]的元素low[j],以a[i]更新low[j]
//注意到low数组内部一定是单调不降的，可二分查找出第一个
//大于等于a[i]的元素
const int maxn = 300003, INF = 0x7f7f7f7f;
int low[maxn], a[maxn];
int n, ans;
int binary_search(int *a, int r, int x)
{
	int l = 1, mid;
	while (l <= r)
	{
		mid = (1 + r) >> 1;
		if (a[mid] <= x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
		low[i] = INF;
	}
	low[1] = a[1];
	ans = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] >= low[ans]) low[++ans] = a[i];
		else
			low[binary_search(low, ans, a[i])] = a[i];
	}
	printf("%d\n", ans);
	return 0;
}