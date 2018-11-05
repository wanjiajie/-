#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define inf 1 << 25
#define LL long long
using namespace std;
int row[10][10];
int col[10][10];
int map[10][10];
int small[10][10];
int f(int x,int y)
{
	return 3 * ((x - 1) / 3) + (y - 1) / 3 + 1;
}
void init()
{
	int i, j;
	char ch;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(small, 0, sizeof(small));
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			scanf("%c", &ch);
			map[i][j] = ch - '0';
			if (map[i][j])
			{
				int k;
				k = f(i, j);
				row[i][map[i][j]] = 1;
				col[j][map[i][j]] = 1;
				small[k][map[i][j]] = 1;

			}
		}
		getchar();
	}
}
int dfs(int x,int y)
{
	if (x == 10) return 1;
	int flag = 0;
	if (map[x][y])
	{
		if (y == 9)  flag = dfs(x + 1, 1);
		else  flag = dfs(x, y + 1);
		if (flag)
			return 1;
		else
			return 0;
	}
	else
	{
		int k = f(x, y);
		for (int i = 1; i <= 9; i++)
		{
			if (!row[x][i] && !col[y][i] && !small[k][i])
			{
				map[x][y] = i;
				row[x][i] = 1;
				col[y][i] = 1;
				small[k][i] = 1;
				if (y == 9)  flag = dfs(x + 1, 1);
				else
					flag = dfs(x, y + 1);
				if (!flag)
				{
					map[x][y] = 0;
					row[x][i] = 0;
					col[x][i] = 0;
					small[k][i] = 0;
				}
				else
					return 1;

			}

		}

	}
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		init();
		dfs(1, 1);
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}