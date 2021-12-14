#include <stdio.h>
#include <stdlib.h>

int main(){
    int testcases = 0;
    scanf("%d",&testcases);
    int* ns = (int*)malloc(testcases*sizeof(int));
    int i =0;
    int j = 0;
    int k=0;
    for ( i = 0; i < testcases; i++)
    {
        scanf("%d",&ns[i]);
    }
    for ( i = 0; i < testcases; i++)
    {
       for ( j = 2,k=0; k < ns[i];k++, j++)
       {
           printf("%d ",j);
       }
       printf("\n");
    }
    
}