/*
La longitud de la base es una potencia de 2. Thanos quiere destruir la base usando el minimo poder.
empieza por toda la bsae y en un paso puede hacer lo siguiente:
    -Si la longitud es almenos 2, divide la base en 2 y las destruye por separado, o
    -quema la base actual, si no contiene ningun avenger dentro, le toma A cantidad de poder, 
    de otra manera toma B*na*I cantidad de poder, donde na  es el numero de vengadores y l es la longitud
    actual de la base
imprime el minimo poder necesitado por thanos para destruir la base
 
 
    n,k,A y B (1<=n<=30,1<=k<=10^5,1<=A,B<=10^4) donde 2^n es la longitud de la base, k el numero de vengadores
        y A y B son constantes ya explicadas
    la segunda linea contiene k enteros  a1,a2,a3...ak (1<=ai<=2^n) deonde ai representa la posicion del 
    vengador en la base
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int A = 1;
int B = 2;
int CreativeSnap(int *base, int longitud)
{
    if (longitud == 1)
    {
        if (*base == 0)
        {
            return A;
        }
        return B * (*base);
    }
    int *baseIzq = base;
    int *baseDer = base + longitud / 2;
    int PrevPower = CreativeSnap(baseIzq, longitud / 2) + CreativeSnap(baseDer, longitud / 2);
    int ActPower = 0;
    int i, VengadoresEnBase = 0;
    for (i = 0; i < longitud; i++)
    {
        if (base[i] != 0)
        {
            VengadoresEnBase += base[i];
        }
    }
    if (VengadoresEnBase == 0)
    {
        ActPower = A;
    }
    else
    {
        ActPower = B * VengadoresEnBase * longitud;
    }
 
    if (ActPower > PrevPower)
    {
        return PrevPower;
    }
    else
    {
        return ActPower;
    }
}
 
int main()
{
    int n = 2, k = 2;
    scanf(" %i %i %i %i ", &n, &k, &A, &B);
    int longitud = pow(2, n);
    int arr[longitud];
    int i;
    long int linea[k];
    for (i = 0; i < longitud; i++)
    {
        arr[i] = 0;
    }
 
   
    for (i = 0; i < k; i++)
    {
        scanf("%ld",&linea[k]);
        arr[linea[k]-1]+=1;
    }
    printf("%d", CreativeSnap(arr, longitud));
}