#include <stdio.h>

int main() 
{
    int m, n;
    scanf("%d%d", &m, &n);
    int i;
    int sum  = 0;
    for (i = m; i<=n; i++) 
    {
        sum += (i*i);
    }
    printf("%d ", sum);
    return 0;
}