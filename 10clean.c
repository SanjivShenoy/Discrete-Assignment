#include<stdio.h>

int A[100000], B[100000], C[100000];

int main()
{
    int n, e, flag, indexA=0, indexB=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        int m, inc=0;
        scanf("%d", &m);
        int temp[(2*m)];

        for(int j=0; j<(2*m); j++)
        {
            flag = 0;
            scanf("%d", &e);
            temp[inc] = e;
            inc++;
            for(int k=0; A[k]!=0; k++)
            {
                if(A[k]==e)
                {
                    C[k]+=1;
                    flag=1;
                }
            }
            if(flag==0)
            {
                A[indexA] = e;
                C[indexA]+=1;
                indexA++;
            }
        }

        char c;
        scanf("%c", &c);

        while(c == 32 || c == 10)
        {
            scanf("%c", &c);
        }

        if(c == '>' || c == '<')
        {
            for(int j=0; j<(2*m); j++)
                for(int k=0; A[k]!=0; k++)
                    if(A[k] == temp[j])
                        B[k] = 1;
        }

        else
        {
            for(int j=0; j<2*m; j++)
                for(int k=0; A[k]!=0; k++)
                    if(A[k] == temp[j])
                        B[k] = -1;
        }

    }

    for(int i=0; B[i]!=0 ; i++)
    {
        if(B[i] == -1)
        C[i] = -1;
    }

    int max = 0;

    for(int i=0; C[i] != 0; i++)
    {
        if(C[i]>max)
        max=C[i];
    }

    int ans;
    for(int i=0; C[i] != 0; i++)
    {
        if(C[i] == max)
        ans = A[i];
    }

    for(int i=0; C[i] != 0; i++)
        if(C[i] == max)
        {
            C[i] = -2;
            break;
        }

    for(int i=0; C[i]!= 0; i++)
        if(C[i] == max)
        {
            printf("ans = %d", -1);
            return 0;
        }

    printf("ans = %d", ans);
    return 0;
}
