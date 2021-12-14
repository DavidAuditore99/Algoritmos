#include <stdio.h>

int main(){
    int testCases = 0;
    scanf("%d",&testCases);
    int i;
    for ( i = 0; i < testCases; i++)
    {
        int n;
        scanf("%d",&n);
        int j;
        int a[n];
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&a[j]);
        }
        int x = a[n-1];
        int cont =0;
        for (j = n-2; j>=0; j--)
        {
            if (a[j]>x)
            {
                x = a[j];
                cont ++;
            }
        }
        printf("%d\n", cont);
    }
    

}