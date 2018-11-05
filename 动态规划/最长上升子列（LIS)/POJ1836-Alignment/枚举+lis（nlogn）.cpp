#include<iostream>
using namespace std;
const int inf = 3;
//ord[]为不降序列，返回str中比digit小的最大的那个数的（下标+1）
int binary_search_1(double ord[], double digit, int head, int len)
{
	int left = head, right = len;
	int mid;
	while (right != left)
	{
		mid = (left + right) / 2;
		if (digit == ord[mid])
			return mid;
		else if (digit < ord[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
//ord[]为不升序列
int binary_search_2(double ord[], double digit, int head, int len)
{
	int left = head, right = len;
	int mid;
	while (right != left)
	{
		mid = (left + right) / 2;
		if (digit == ord[mid])
			return mid;
		else if (digit > ord[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main(int i,int j)
{
	int n;
	while (cin >> n)
	{
		double*h = new double[n + 1];
		for (i = 1; i <= n; i++)
			cin >> h[i];
		int max = 0;
		for (int m = 1; m <= n; m++)//对h[]每一个值作为分界点，进行枚举
		{
			double*ord = new double[n + 1];
			//DP-(0`m)-LIS
			ord[0] = -1;//下界无穷小
			int len_LIS = 1;
			for (i = 1; i <= m; i++)
			{
				ord[len_LIS] = inf;//上界无穷大
				j = binary_search_1(ord, h[i], 0, len_LIS);
				if (j == len_LIS) len_LIS++;
				ord[j] = h[i];
			}
			len_LIS--;//减去ord[0]的长度1
			//DP-(m+1`n)-LDS
			ord[m] = inf;
			int len_LDS = 1;
			for (i = m + 1; i <= n; i++)
			{
				ord[m + len_LDS] = -1;
				j = binary_search_2(ord, h[i], m, m + len_LDS);
				if (j == m + len_LDS) len_LDS++;
					ord[j] = h[i];
			}
			len_LDS--;
			if (max < len_LIS + len_LDS) max = len_LIS + len_LDS;
			delete ord;
		}
		cout << n - max << endl;
		delete h;
	}
	return 0;
	
}