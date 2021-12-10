#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char longComp(int num1, long long int num2)
{
    if (num1 > num2)
    {
        return '>';
    }
    if (num1 < num2)
    {
        return '<';
    }
    return '=';
}
 
int main()
{
    int testCases = 0;
    scanf("%d", &testCases);
    long long  x[testCases * 2];
    long long  p[testCases * 2];
     int i = 0;
    for (i = 0; i < testCases; i++)
    {
        scanf("%lld %lld", &x[i * 2], &p[i * 2]);
        scanf("%lld %lld", &x[i * 2 + 1], &p[i * 2 + 1]);
        if (p[i * 2] <= p[i * 2 + 1])
        {
            p[i * 2 + 1] -= p[i * 2];
            p[i * 2] = 0;
        }
        else
        {
            p[i * 2] -= p[i * 2 + 1];
            p[i * 2 + 1] = 0;
        }
        p[i * 2] = pow(10.00000000001, p[i * 2]);
        p[i * 2 + 1] = pow(10.0000000001, p[i * 2 + 1]);
    }
    for (i = 0; i < testCases; i++)
    {
        long long int num1 =abs( x[i * 2] * p[i * 2]);
        long long int num2 = abs(x[i * 2 + 1] * p[i * 2 + 1]);
        if (i == 550)
        {
           // printf("%lld-%lld-%lld-%lld-%lld-%lld",x[i * 2] , p[i * 2],x[i * 2 + 1] , p[i * 2 + 1],num1,num2);
            printf("<\n");
        }
        
        if (num1 > num2 ||((x[i * 2]>x[i * 2 + 1])&& (p[i * 2]>p[i * 2 + 1])))
        {
            printf(">\n");
            continue;
        }
            if (num1 < num2)
            {
                printf("<\n");
            continue;
            }
                printf("=\n");
            }
}