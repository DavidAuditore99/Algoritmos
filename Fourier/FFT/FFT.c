#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int esPotenciaDeDos(int n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}
void SeparaArreglo(int longitud, float* toDivideArray,float* pares, float* impares ){
    int i;
    for ( i = 0; i < longitud; i++)
    {
        if (i%2==0)
        {
            pares[i/2]= toDivideArray[i];
        }else{
            impares[(i-1)/2]= toDivideArray[i];
        }
        
    }
    
}
void FFT(float *a, int longArr, float *YReales, float* YComplex)
{
    int n = longArr;
    if (n == 1)
    {
        YReales[0]= *a;
        YComplex[0] = 0.0;
    }
    float wnReal= cos(2*M_PI/n);
    float wnImg=  sin(2*M_PI/n);
    float wreal=1;
    float wimg=1;
    float a0[n/2];
    float a1[n/2];
    SeparaArreglo(n,a,a0,a1);
    FFT(a0,n/2,YReales,YComplex);
    FFT(a1,n/2,YReales,YComplex);
    int k;
    for ( k = 0; k < n/2; k++)
    {
        YReales[k]=YReales[k] + wreal*YReales[k];
        YComplex[k]=YComplex[k] + wimg*YComplex[k];
        YReales[k+(n/2)] = YReales[k] - wreal*YComplex[k];
        YComplex[k+(n/2)] = YComplex[k] - wimg*YComplex[k];
        wreal = wreal*wnReal;
        wimg = wimg * wnImg;
    }
}
int main()
{
    int n, i = 0;
    printf("Cuantos datos quiere escanear? Debe ser potebcia de 2 \n");
    //scanf("%d", &n);
    n=4;
    float *arr =(float *)malloc(n * sizeof(float));
    float *YReales = (float *)malloc(n * sizeof(float));
    float *YComplex = (float *)malloc(n * sizeof(float));
    if (esPotenciaDeDos(n)){
        /*for (i = 0; i < n; i++)
        {
            printf("Inserte el elemento %d.- ", i);
            scanf("%f", &arr[i]);
        }*/
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        arr[3]=4;
        for ( i = 0; i < n; i++)
        {
            YReales[i]=0.0;
            YComplex[i]=0.0;
        }
        FFT(arr,n,YReales,YComplex);
    }
    else
    {
        printf("'%d' No Es Potencia de 2", n);
        main();
    }
        for ( i = 0; i < n; i++)
        {
            printf("arr1: %f arr2; %f \n",YReales[i],YComplex[i]);
        }
    return 0;
}