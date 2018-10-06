#include<stdio.h>


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int Arr[m], Brr[m], Crr[m],Drr[100000];
    int p=1, flag = 0, count=0;

    for(int i=0; i<m; i++)
        Crr[i]=-1;

    for(int i=0; i<100000; i++)
        Drr[i] = -1;

    for(int i=0; i<m; i++)
        scanf("%d %d", &Arr[i], &Brr[i]);

    Drr[0] = 0;

    int j=0;
    for(int i=0; i<m; i++)
        if(Arr[i] == 0)
        {
            Drr[p++]=Brr[i];
            Crr[j++] = Brr[i];
        }

    for(int i=0; i<m; i++)
    {
        int x = 0, temp[m];
        for(int k=0; k<m; k++)
        {
            temp[k] = Crr[k];
            Crr[k] = -1;
        }

        for(int k=0; k<m; k++)
            for(int l=0; l<m; l++)
                if(temp[k]==Arr[l])
                {
                    Drr[p++]=Brr[l];
                    Crr[x++] = Brr[l];
                }
    }

    printf("\n" );

    for(int i=0; i<n; i++)
    {
        flag = 0;
        for(int j=0; j<100000; j++)
            if(Drr[j]==i)
                flag = 1;

        if(flag==1)
            printf("%d ",i);
    }

    printf("\n" );
    return 0;
}
