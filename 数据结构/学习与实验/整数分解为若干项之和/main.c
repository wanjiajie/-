#include <stdio.h>
#include <stdlib.h>
#define MAXN 30
int Terms[MAXN];
int N;
int count;
void search(int remainer,int start,int nterm);

int main()
{
    scanf("%d",&N);
    count=0;
    search(N,1,0);
    if (count%4£¡=0£©
        printf("\n");
    return 0;

}

void search(int remainer,int start,int nterm)
{
    int i;
    if(remainer==0){
        count++;
        if(count%4!=1)
            printf(";");
       printf("%d=%d",N,terms[0]);
       for(i=1;i<nterm;i++)
            printf("+d",terms[i]);
       if(count%4==0)
        printf("\n");
    }
    else
    for(i=0)

}
