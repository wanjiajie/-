 //#include"big.h"
 //�������ӷ�д��һ��������Ȼ����main�����е��á�
 #include<stdlib.h>
 #include<stdio.h>
 #include<string.h>
 char * bigadd(char *adda, int lena, char *addb, int lenb)   //�ӷ�����ķ�����
 {     
	   int num = '0', i, k, j, tmp;
	   for (i = 0; i < lena; i++)
	   {                                                          //���ַ����������ת��Ϊ��Ӧ������
		       adda[i] = adda[i] - num;                                  //����6ʵ�����ַ����д洢����54��
		}                                                         //��ȥ0��Ӧ��48�õ���ʵ��6�洢���ַ������С�
	   for (i = 0; i < lenb; i++) {
		       addb[i] = addb[i] - num;
		
	}
	    int lensum;                                             //����������ĳ��ȡ�
	     lensum = lena > lenb ? lena : lenb;
	     lensum=lensum+2;
	     char *result, final[BUFSIZ];                             //result���ڷ��ؽ������final������������������
	    result = (char*)calloc(lensum, 1);
	     for (i = 0, j = 0; i < lena&&j < lenb; i++, j++) {                    //ѭ���ĸ�ÿһλ���ӷ�
		       result[i] = adda[lena - i - 1] + addb[lenb - j - 1];
		
	}
	    if (lena > lenb) {                                          //ʹ���жϽ��ϴ����ĸ�λҲд��������
		       for (i = lenb; i < lena; i++) {
			          result[i] = adda[lena - i - 1];
			
		}
		
	}
	     if (lenb > lena) {
		      for (i = lena; i < lenb; i++) {
			         result[i] = addb[lenb - i - 1];
		
		}
		
	}
	    for (k = 0; k < lensum - 1; k++) {                                //�����������ÿһλ����10��һ��
		     if (result[k] > 9) {
			         tmp = result[k] / 10;
			          result[k] = result[k] % 10;
			          result[k + 1] += tmp;
			
		}
		
	}
	   j = 0;
	    if (result[lensum-2] != 0) {                                 //ȥ��ǰǰ��0����������д��final�����С�
		       final[j] = result[lensum - 2] + '0';
		j++;
		
	}
	   for (i = lensum - 3; i >= 0; i--) {
		      final[j++] = result[i] + '0';
	}
	   memcpy(result, final,lensum);                                           //�ٰ�resultָ��ָ��final�����У�������resultָ�롣    
	    return result;
	
}
 int main() {                                                 //����main���Է�������puts��ӡ�����               
	    int lena, lenb;
	   char *result, sa[BUFSIZ], sb[BUFSIZ];
	   scanf("%s", sa);
	   scanf("%s", sb);
	    lena =(int)strlen(sa);
	    lenb =(int)strlen(sb);
	    result = bigadd(sa, lena, sb, lenb);
		puts(result);		
}


