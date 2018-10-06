#include<stdio.h>

void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r, int Krr[], int p);

void printCombination(int arr[], int n, int r, int Krr[], int p)
{
    int data[r];

    combinationUtil(arr, data, 0, n-1, 0, r, Krr, p);
}


void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r, int Krr[], int p)
{

    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        for(int x=0; x<p; x++)
        {
            printf("%d ", Krr[x]);
        }

        printf("\n");
        return;  //////important
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r, Krr, p);
    }
}

int main()
{
    int N, K, L, flag, p=0;

    scanf("%d", &N);
    int Srr[N];

    for(int i=0; i<N; i++)
        scanf("%d", &Srr[i]);

    scanf("%d", &K);
    int Grr[K];

    for(int i=0; i<K; i++)
        scanf("%d", &Grr[i]);

    scanf("%d", &L);
    int Rrr[L], Krr[L];

    for(int i=0; i<L; i++)
        scanf("%d", &Rrr[i]);

    for(int i=0; i<L; i++)
    {
        flag = 0;
        for(int j=0; j<K; j++)
            if(Rrr[i] == Grr[j])
            {
                flag = 1;
                break;
            }

        if(flag == 0)
            Krr[p++] = Rrr[i];
    }

    printf("\n\n");

    for(int i=0; i<=K; i++)
        printCombination(Grr, K, i, Krr, p);
    return 0;
}
