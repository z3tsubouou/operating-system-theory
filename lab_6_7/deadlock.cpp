#include <stdio.h>

int main()
{

    int n, m, i, j, k;
    n = 5;
    m = 4;
    int alloc[5][4] = {{0, 0, 1, 2},
                       {1, 0, 0, 0},
                       {1, 3, 5, 4},
                       {0, 6, 3, 2},
                       {0, 0, 1, 4}};

    int max[5][4] = {{0, 0, 1, 2},
                     {1, 7, 5, 0},
                     {2, 3, 5, 6},
                     {0, 6, 5, 2},
                     {0, 6, 5, 6}};

    int avail[4] = {1, 5, 2, 0};

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("1: \n   ");
    for (i = 0; i < n - 1; i++)
        printf("P%d ->", ans[i]);
    printf(" P%d\n\n", ans[n - 1]);

    printf("2: Buh processiin need\n    ");
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", max[i][j] - alloc[i][j]);
        }
        printf("\n    ");
    }

    int second_max[5][4] = {{0, 0, 1, 2},
                            {1, 4, 2, 0},
                            {2, 3, 5, 6},
                            {0, 6, 5, 2},
                            {0, 6, 5, 6}};

    printf("\n");
    printf("3: P1 Need(0,4,2,0) baih uyed shuud biyeluuleh bolomjtoi\n    ");

    f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = second_max[i][j] - alloc[i][j];
    }
    y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < n - 1; i++)
        printf("P%d ->", ans[i]);
    printf(" P%d\n\n", ans[n - 1]);

    return (0);
}