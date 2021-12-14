#include <stdio.h>

int main(){
    int testCases=0;
    scanf("%d",&testCases);
    int i;
    for ( i = 0; i < testCases; i++)
    {
        int j;
        long long int b[7];
        
        for ( j = 0; j < 7; j++)
        {
            scanf("%lld",&b[j]);
        }
        printf("%lld %lld ",b[0],b[1]);
        if ((b[0]+b[1]) == b[2] )
        {
            printf("%lld",b[3]);
        }else{
            printf("%lld",b[2]);
        }
            printf("\n");
        
    }
    
}