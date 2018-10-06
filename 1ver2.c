#include<stdio.h>

int i,j,num,s=0,edge=0;
int a[10000];

int isprime(int n)
{
    int i;
    for(i=2; i*i<=n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

int main()
{
    scanf("%d", &num);
    for(i=1; i<=num/2; i++)
        if(num%i == 0)
            a[s++] = i;
    a[s++] = num;

    for(i=0; i<s; i++)
        for(j=0; j<i; j++)
            if(a[i]%a[j]==0)
                if(isprime(a[i]/a[j]))
                    edge++;

    printf("%d", edge);
    return 0;
}
