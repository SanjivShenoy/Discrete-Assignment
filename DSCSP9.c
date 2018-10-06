#include<stdio.h>

int a[1441]; //a[0] not included

int main()
{
    int n;
    scanf("%d", &n);
    int me,mx;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &me,&mx);
        for(int j=me; j<=mx; j++)
        {
            a[j]+=1;
        }
    }
    int max=0;
    for(int i=1;i<1441;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }

    printf("%d", max);
    return 0;
}
