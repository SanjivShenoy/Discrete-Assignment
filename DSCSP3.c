#include<stdio.h>

void initialize(int Arr[], int N)
{
    for(int i=0; i<N; i++)
    {
        Arr[i]=i;
    }
}


void Union(int Arr[], int N, int A, int B)
{
        int Temp = Arr[ A ];
    for(int i=0; i<N; i++)
    {
        if(Arr[i] == Temp)
        Arr[i] = Arr[B];
    }
}

int main()
{
    int n,m;
    int p1,p2;
    scanf("%d %d", &n, &m);
    int arr[n];
    int flag, count;

    initialize(arr, n);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &p1, &p2);
        Union(arr, n, p1, p2);
    }


    for(int i=0; i<n; i++)
    {
        flag = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[j]==i)
            {
                flag = 1;
            }
        }
        if(flag==1)
            count++;
    }

    printf("No. of pipes = %d\n", count);
    return 0;
}
