//״̬��ƣ�f[i]������a[i]��β��LIS����
//״̬ת�ƣ�f[i]=max{f[i]+1}(1<=j<i,a[j]<a[i])
//�߽紦��f[i]=1��i<=i<=n��
//ʱ�临�Ӷȣ�O{n^2)
const int maxn = 103, INF = 0x7f7f7f;
int a[maxn], f[maxn];
int n, ans = -INF;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[j] < a[i])
				f[i] = (f[i] > f[j] + 1) ? f[i] : f[j] + 1;
	for (int i = 1; i <= n; i++)
		ans = (ans > f[i]) ? ans : f[i];
	printf("%d\n"��ans);
	return 0;
}