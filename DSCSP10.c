#include<stdio.h>

int A[100000];
int B[100000];
int C[100000];

int main()
{
    int n, flag;
    scanf("%d", &n);
    int indexA=0, indexB=0;
    int e;

    for(int i=0; i<n; i++)
    {
        int m;
        scanf("%d", &m);
        int temp[(2*m)];
        int inc=0;

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
/*///////////
        printf("\n\n\n");
        for(int k=0;k<2*m;k++)
        printf("%d ",temp[k]);
        printf("\n\n");
//////////*/

        if(c == '>' || c == '<')
        {
            for(int j=0; j<(2*m); j++)
            {
                for(int k=0; A[k]!=0; k++)
                {
                    if(A[k] == temp[j])
                    {
                        B[k] = 1;
                    }
                }
            }
        }

        else
        {
            for(int j=0; j<2*m; j++)
            {
                for(int k=0; A[k]!=0; k++)
                {
                    if(A[k] == temp[j])
                    {
                        B[k] = -1;
                    }
                }
            }
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
    {
        if(C[i] == max)
        {
            C[i] = -2;
            break;
        }
    }

    for(int i=0; C[i]!= 0; i++)
    {
        if(C[i] == max)
        {
            printf("ans = %d", -1);
            return 0;
        }
    }

/*//checking
    printf("max = %d\n", max);
    printf("A[i] = ");
    for(int i = 0; A[i] != 0; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("B[i] = ");
    for(int i = 0; B[i] != 0; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("C[i] = ");
    for(int i = 0; i<12; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
//checking*/
    printf("ans = %d", ans);
    return 0;
}
