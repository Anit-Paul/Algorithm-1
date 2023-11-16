#include <stdio.h>
#define max 99999999
int solution(int d[], int size)
{
    int n = size - 1;
    int cost[size][size], cut[size][size];
    for (int i = 0; i <= n; i++)
    {
        cost[i][i] = 0;
    }
    for (int l = 2; l <= size; l++)
    {
        for (int i = 0; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            cost[i][j] = max;
            for (int k = i; k < j; k++)
            {
                int q = cost[i][k] + cost[k + 1][j] + (d[i] * d[k + 1] * d[j + 1]);

                if (cost[i][j] > q)
                {
                    cost[i][j] = q;
                    cut[i][j] = k + 1;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    printf("\n----------------------------------------------------\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d\t", cut[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int size;
    printf("size : ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("element : ");
        scanf("%d", &a[i]);
    }
    size = size - 1;
    solution(a, size);
    return 0;
}