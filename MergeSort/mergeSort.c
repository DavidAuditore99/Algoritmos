#include <stdio.h>
#include <stdlib.h>
/*
    arr: Arreglo a dividir
    longitud: longitud del arreglo
    izq: arreglo izquierdo
    der: arreglo derecho
*/
int *MergeSort(int *arr, int longitud)
{
    if (longitud == 1)
    {
        return arr;
    }
    int *izq = (arr);
    int *der = (arr + (longitud / 2));
    int i;

    izq = MergeSort(izq, longitud / 2);
    der = MergeSort(der, longitud / 2);
    int comp1, comp2 = 0;
    int contizq=0,contder=0;
    int* ordenado=(int*)malloc(longitud*sizeof(int));
    for (i = 0; i < longitud; i++)
    {
        comp1 = *izq;
        comp2 = *der;
            if (i==longitud-1)
            {
                if (contizq==longitud/2)
                {
                    ordenado[i]=*der;
                }
                if (contder==longitud/2)
                {
                    ordenado[i]=*izq;
                }
                break;
            }
        if (comp1 < comp2)
        {
            if (contizq == longitud/2 &&i!=longitud-1 )
            {
                ordenado[i]=comp2;
            der++;
            }else{
            ordenado[i] = comp1;
            contizq++;
            izq++;
            }
        }
        else
        {
            if (contder == longitud/2&&i!=longitud-1)
            {
                ordenado[i]=comp1;
            izq++;
            }else{
            ordenado[i] = comp2;
            contder++;
            der++;
            }
        }
    }
    
    
    return ordenado;

}

int main()
{
    int arr[] = {4, 2,10, 8,5,6,20,15};
    int *arr2 = MergeSort(arr, 8);
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d--", arr2[i]);
    }
    printf("\n----\n");
}