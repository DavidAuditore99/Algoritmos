#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testCases = 0;
    int n = 0;
    int i, j;
    scanf("%d", &testCases);
    int *altura = (int *)malloc(testCases * sizeof(int));
    int diaAnt = 0;
    int diaActual = 0;
    for (i = 0; i < testCases; i++)
    {
        altura[i] = 1;
        scanf("%d", &n);
        diaAnt = 0;
        printf("%d",n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &diaActual);

            if (diaAnt == 1 && diaActual == 1)
            {
                altura[i] += 5;
                continue;
            }
            if (diaAnt == 0 && diaActual == 0)
            {
                altura[i] = -1;
                break;
            }
            if ((diaAnt == 0 && diaActual == 1) || (diaAnt == 1 && diaActual == 0))
            {
                diaAnt = diaActual;
                altura[i]++;
                continue;
            }
        }
    }
    for (i = 0; i < testCases; i++)
    {
        printf("%d\n", altura[i]);
    }
}