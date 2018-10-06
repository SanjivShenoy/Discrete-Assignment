#include<stdio.h>

int main()
{
    int n, flag, count=0;
    scanf("%d", &n);
    char a[n], b[n];
    int freq[130];

    for(int i=0; i<130; i++)
        freq[i] = -1;

    for(int i=0; i<n; i++)
    {
        scanf("\n%c", &a[i]);
        //while(a[i] == 32 || a[i] == 10)
            //scanf("%c", &a[i]);

        scanf("\n%c", &b[i]);
        //while(b[i] == 32 || b[i] == 10)
            //scanf("%c", &b[i]);
    }

    for(int i=0; i<n; i++)
        freq[a[i]]=freq[b[i]]=0;

    for(int i=0; i<n; i++)
        freq[b[i]]++;

    for(int i=96; i<130; i++)
    {
        if(freq[i] >= 0)
            count+=1;
    }

    for(int k=0; k<count; k++)
    {
        flag = 0;
        for(int i=96; i<130; i++)
            if(freq[i] == 0)
            {
                char c = i;
                printf("%c", c);

                for(int j=0; j<n; j++)
                    if(a[j] == c)
                        freq[b[j]]--;

                flag = 1;
                freq[i]=-1;
                break;
            }

        if(flag == 0)
        {
            printf("%d", -1);
            break;
        }
    }
    return 0;
}
