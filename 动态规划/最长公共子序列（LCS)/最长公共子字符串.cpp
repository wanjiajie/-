//状态转移方程为：如果xi==yj，则c[i][j]==c[i-1][j-1]+1
//如果xi！=yj，那么c[i][j]=0
//则lcs长度为max{c[i][j],1<=i<=n,1<=j<=m}
int longest_common_substring(char *str1, char *str2)
{
	int i, j, k, len1, len2, max, x, y;
	len1 = strlen(str1);
	len2 = strlen(str2);
	int **c = new int*[len1 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i] = new int[len2 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i][0] = 0;
	for (j = 0; j < len2 + 1; j++)
		c[0][j] = 0;
	max = -1;
	for(i=1;i<len1+1;i++)
		for (j = 1; j < len2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
		}
		else c[i][j] = 0;
		if (c[i][j] > max)
		{
			max = c[i][j];
			x = i;
			y = j;                                                                                                      
		}
		char s[1000];
		k = max;
		i = x - 1, j = y - 1;
		s[k--] = '\0';
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == str2[j])
			{
				s[k--] = str1[i];
				i--;
				j--;
			}
			else
				break;
		}
		printf("最长公共子串为：   ");
		puts(s);
		for (i = 0; i < len1 + 1; i++)
			delete[]c[i];
		delete[]c;
		return amx;

}