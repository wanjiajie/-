//�½�һlow���飬low[i]��ʾ����Ϊi��LIS��βԪ�ص���Сֵ��
//����һ�������У���Ȼ���βԪ��ԽС��Խ�������ں���
//������Ԫ�أ�Ҳ��Խ���ܱ�ø�������ˣ�ֻ��ά��low����
//����ÿһ��a[i]����a[i]>low[��ǰ�lis����],�Ͱ�a[i]
//�ӵ���ǰ���lis���棬��low[++��ǰ���lis����]
//=a[i]�����򣬾���a[i]����low���顣���巽������low������
//�ҵ���һ�����ڵ���a[i]��Ԫ��low[j],��a[i]����low[j]
//ע�⵽low�����ڲ�һ���ǵ��������ģ��ɶ��ֲ��ҳ���һ��
//���ڵ���a[i]��Ԫ��
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