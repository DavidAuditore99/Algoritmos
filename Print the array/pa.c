#include <stdio.h>

int main()
{
    int testcases = 0;
    scanf("%d", &testcases);
    int i;
    for (i = 0; i < testcases; i++)
    {
        int j;
        int n;
        scanf("%d", &n);
        long long int a[n];
        for (j = 0; j < n; j++)
        {
            scanf("%lld", &a[j]);
        }
        for (j = 0; j < n; j++)
        {
            int blue = 0;
            int red = 0;
            int k;
            for (k = 0; k < n; k++)
            {
                if (a[k] % a[j] == 0)
                {
                    blue++;
                    red = 0;
                    if (blue == 2)
                    {
                        break;
                    }
                }
                else
                {
                    red++;
                    blue = 0;
                    if (red == 2)
                    {
                        break;
                    }
                }
            }
            if (blue != 2 && red != 2)
            {
                printf("%lld\n", a[j]);
                break;
            }
            if (j == n - 1)
            {
                printf("0\n");
            }
        }
    }
}