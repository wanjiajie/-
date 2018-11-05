#include<iostream>
using namespace std;
const int inf = 3;
//ord[]Ϊ�������У�����str�б�digitС�������Ǹ����ģ��±�+1��
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
//ord[]Ϊ��������
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
		for (int m = 1; m <= n; m++)//��h[]ÿһ��ֵ��Ϊ�ֽ�㣬����ö��
		{
			double*ord = new double[n + 1];
			//DP-(0`m)-LIS
			ord[0] = -1;//�½�����С
			int len_LIS = 1;
			for (i = 1; i <= m; i++)
			{
				ord[len_LIS] = inf;//�Ͻ������
				j = binary_search_1(ord, h[i], 0, len_LIS);
				if (j == len_LIS) len_LIS++;
				ord[j] = h[i];
			}
			len_LIS--;//��ȥord[0]�ĳ���1
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