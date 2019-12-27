#include <stdio.h>

int main() {
    int x;
    float y;
    scanf("%d", &x);
    scanf("%f", &y);
    
    if (x == 1) {
        printf("%.2f",(1.8 * y) + 32 );
    }
    if (x == 2) {
        printf("%.2f",(y - 32)/1.8);
    }

    return 0;
}