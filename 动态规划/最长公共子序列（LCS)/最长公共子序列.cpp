#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int LCSLength(char *str1, char *str2, int **b)
{
	int i, j, len1; len2; len;
	len1 = strlen(str1);
	len2 = strlen(str2);
	int **c = new int*[len1 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i] = new int*[len2 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i][0] = 0;
	for (j = 0; j < len2 + 1; j++)
		c[0][j] = 0;
	for(i=1;i<len1+1;i++)
		for (j = 1, j < len2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				c[i][j] = c[i - 1][j-1]+1;
				b[i][j] = 0;//输出公共子串时搜索方向
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	len = c[len1][len2];
	for (i = 0; i < len1 + 1; i++)
		delete[]c[i];
	delete[]c;
	return len;

}
void PritnLCS(int**b, char *str1, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, str1, i - 1, j - 1);
		printf("%c", str1[i - 1]);
	}
	else if (b[i][j] == 1)
		PrintLCS(b, str1, i - 1, j);
	else
		PrintfLCS(b, str1, i, j - 1);
}
int main()
{
	char str1[100], str2[100];
	int i, len1, len2, len;
	printf("请输入第一个字符串：");
	gets(str1);
	len1 = strlen(str1);
	len2 = strlen(str2);
	int **b = new int*[len1 - 1];
	for (i = 0; i < len1 + 1; i++)
		b[i] = new int[len2 + 1];
	len = LCSLength(str1, str2, b);
	printf("最长公共子序列长度为：%d\n"，len);
	pritnf("最长公共子序列长度为：");
	PrintLCS(b, str1, len1, len2);
	printf("\n");
	for (i = 0; i < len1 + 1; i++)
		delete[]b[i];
	delete[]b;
	system("pause");
	return 0;
}