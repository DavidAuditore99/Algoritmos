#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int A = 1;
int B = 2;
int CS(int *posiciones, int k, int min, int max)
{
    int dif = max - min + 1;
    if (max == min)
    {
        int i;
        for (i = 0; i < k; i++)
        {
            if (posiciones[i] == max)
            {
                return B;
            }
        }
        return A;
    }
    int i = 0, j = 0;
    int actpow = A;
    int cont = 0;
    for (i = 0; i < k; i++)
    {
        if (posiciones[i] >= min && posiciones[i] <= max)
        {
            cont++;
        }
    }
    if (cont==0)
    {
        return A;
    }
    if (cont > 0)
    { 
        actpow = (dif) * cont * B;
    }
    int totpow = CS(posiciones, k, min, max - (dif / 2)) + CS(posiciones, k, max - dif / 2 + 1, max);
    if (actpow > totpow)
    {
        return totpow;
    }
    return actpow;
}
int main()
{
    int n = 0, k = 0;
    scanf(" %i %i %i %i ", &n, &k, &A, &B);
    int longitud = pow(2, n);
    int i;
    int *linea = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
    {
        scanf("%d", &linea[i]);
    }
    printf("%d", CS(linea, k, 1, longitud));
}