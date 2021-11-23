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
    
    int londer=longitud/2;
    int lonizq = longitud/2;
    if (longitud%2!=0)
    {
        lonizq = longitud/2;
        londer = longitud - lonizq;
    }
    
    izq = MergeSort(izq, lonizq);
    der = MergeSort(der, londer);
    int comp1, comp2 = 0;
    int contizq=0,contder=0;
    int* ordenado=(int*)malloc(longitud*sizeof(int));
    for (i = 0; i < longitud; i++)
    {
        comp1 = *izq;
        comp2 = *der;
            if (i==longitud-1)
            {
                if (contizq==lonizq)
                {
                    ordenado[i]=*der;
                }
                if (contder==londer)
                {
                    ordenado[i]=*izq;
                }
                break;
            }
        if (comp1 < comp2)
        {
            if (contizq == lonizq  )
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
            if (contder == londer)
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
    int arr[] = {4, 2,10,20,8,9,31,3,1,7,11};
    int *arr2 = MergeSort(arr,11);
    int i;
    for (i = 0; i < 11; i++)
    {
        printf("%d--", arr2[i]);
    }
    printf("\n----\n");
}