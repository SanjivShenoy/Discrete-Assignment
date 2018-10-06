#include<stdio.h>
#include<stdlib.h>

#define N 1005

int n,m,a[N],q[N],ans;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int check(int *a)
{
    int i;
    for(i=0; i<2*m; i+=2)
        if(a[q[i]]>a[q[i+1]])
            return 0;
    return 1;
}

void permute(int *a, int i)
{
    int j;
    if(i == n-1 && check(a))
        ans++;
    else
    {
        for(j=i; j<n; j++)
        {
            swap(a+i,a+j);
            permute(a,i+1);
            swap(a+i, a+j);
        }
    }
}

int main()
{
    int i;
    scanf("%d %d", &n,&m);

    for(i=0;i<n;i++)
    {
        a[i]=i;
    }

    for(i=0; i<m+m; i+=2)
    {
        scanf("%d %d", q+i, q+i+1);
    }

    permute(a, 0);
    if(ans == 0)
        ans--;
    printf("%d", ans);
}
