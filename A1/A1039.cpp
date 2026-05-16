#include <stdio.h>

int main() {
    int n;
    
    long long fact = 1; 

    
    if (scanf("%d", &n) != 1) {
        return 0;
    }

   
    for (int i = 1; i <= n; i++) {
        fact *= i; 
    }

    
    printf("%lld\n", fact);

    return 0;
}