#include <stdio.h>
#include <stdlib.h>

void ordenarMaximos(int *arr,int noMaximos,int longitud){
    int i;
    int k;
    for ( i = longitud-1, k =0; k<noMaximos ; i-=2,k++)
    {
        int aux = arr[i];
        arr[i]= arr[i-1];
        arr[i-1]= aux;
    }
    
}
void ordenarMinimos(int *arr,int noMinimos){
    int i;
    int k;
    for ( i =0,k=0; k <noMinimos; i+=2)
    {
        int aux = arr[i];
        arr[i]= arr[i+1];
        arr[i+1]= aux;
    }
    
}

int main(){
    int testCases = 0;
    scanf("%d",&testCases);
    int nab[3];
    int nabs[3][testCases];
    int **arreglos = (int**)malloc(testCases*sizeof(int*));
    int i;
    int k;
    for ( i = 0; i < testCases; i++)
    {
    int* numeros = (int*)malloc(testCases*sizeof(int));
        scanf(" %d %d %d",&nabs[0][i],&nabs[1][i],&nabs[2][i]);
        for ( k = 1; i <= nabs[0][i]; k++)
        {
            numeros[k-1] = k;
        }
        *(arreglos+i) = numeros;
    }
    for ( i = 0; i < testCases; i++)
    {
        if (nabs[0][i]-2 == nabs[1][i]+nabs[2][i])
        {
            printf("-1\n");
            continue;
        }
        
    }
    
}