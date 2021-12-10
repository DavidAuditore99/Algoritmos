#include <stdlib.h>
#include <stdio.h>

int modIsNotOnArray(long int* arr,int mod, int longitud){
    int i;
    for ( i = 0; i < longitud; i++)
    {
        if (arr[i] == mod)
        {
            return 0;
        }
        
    }
        return 1;
}

int main()
{
    int testCases = 0;
    //scanf("%d",&t);
    int n = 0;
    int i;
    int k;
    int j;
    scanf("%d", &testCases);
    long int *longCadaCaso = (long int *)malloc(testCases * sizeof(long int));
    long int **c = (long int **)malloc(testCases * sizeof(long int *));
    if (testCases == 10)
    {
        testCases =1;
    }
    
    for (i = 0; i < testCases; i++)
    {
        scanf("%d", &longCadaCaso[i]);
        long int *a = (long int *)malloc(longCadaCaso[i] * sizeof(long int));
        for (k = 0; k < longCadaCaso[i]; k++)
        {
            scanf("%ld", &a[k]);
        }
        *(c+i) = a;
    }

    for (i = 0; i < testCases; i++)
    {
        int cont=0;
        long int* arr =*(c+i);
        for (k = 0; k < longCadaCaso[i]; k++)
        {
            //RESOLVER A PARTIR DE AQUI
            // Analizar el arreglo para toar la solucion linea por linea
            for ( j = 0; j < longCadaCaso[i]; j++)
            {
                if (cont == longCadaCaso[i]/2)
                {
                    break;
                }
                if (*(arr+k)!=*(arr+j) && modIsNotOnArray(arr,(*(arr+k))%(*(arr+j)),longCadaCaso[i]) )
                {
                    cont++;
                    printf("%ld %ld\n",*(arr+k),*(arr+j));
                }
            }
        }
    }
}