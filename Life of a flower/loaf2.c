#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testCases = 0;
    int n = 0;
    int i, j;
    scanf("%d", &testCases);
    int altura=0;
    int diaAnt = 0;
    int diaActual = 0;
    for (i = 0; i < testCases; i++)
    {
        altura = 0;
        int alturaProv = 1;
        int noRegada = 0;
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &diaActual);
            if (diaActual == 1)
            {
                alturaProv++;
            }

            if ((diaAnt == 1) && (diaActual == 1))
            {
                alturaProv += 4;
            }
            if ((diaAnt == 0 )&& (j > 0) && (diaActual == 0))
            {
                altura = -1;
            }
            diaAnt = diaActual;
        }
        if (altura != -1)
        {
            printf("%d\n",alturaProv);
        }else
        {
            printf("-1\n");
        }
        diaAnt = 0;
        diaActual= 0;
    }
    
}