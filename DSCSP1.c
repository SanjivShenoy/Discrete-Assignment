#include<stdio.h>

int b[10000];
int a[10000];
int k=1;
int countedge=0;

int isprime(int x){
    for(int i=2; i<=x/2; i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

void Uprime(int n)
{

    int j=0;
    if(isprime(n))
    {
        b[0]=1;
        countedge++;
        return ;
    }

    for(int i=2; i<=n/2; i++)
    {
        if(isprime(i))
        {
            if(n%i==0)
            {
                b[j++]=n/i;
                countedge++;
            }
        }

    }

    return ;
}

int updateA()
{   int index=0;
    int count=0, flag;
    while(b[index] != 0)
    {       flag=0;
            for(int i=0;i<k;i++)  //checking if b[i] already in a
            {
                if(b[index] == a[i])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                a[k] = b[index];
                //printf("a[%d]=%d", k,a[k]);
                b[index]=0;
                k++;
                count++;
            }
            index++;
    }
    return count;
}


int main()
{
    int n, count=0;
    //printf("Hello1");
    scanf("%d",&n);
    //printf("Hello2");
    int index=0;
    a[0]=n;

    int s=0, e=0;

    while(b[index] != 1)
    {
        //printf("Hello!");
        for(int j=s;j<=e;j++)
        {
            //printf("hi");
            Uprime(a[j]);
            count+=updateA();
            //printf("count=%d",count);
        }
        int r=0;

        while(a[r]!=0)
        {
            r++;
        }

        s = e+1;

        e = (r-1); //error line but replacing by e+=(r-1)causes infinite loop no output.....weird
    }

    //printf("count = %d",count);
    printf("%d", countedge );

    return 0;
}
