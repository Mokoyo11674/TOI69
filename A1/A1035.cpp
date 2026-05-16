#include <stdio.h>

int main() {
    int n;
    int sum = 0; 
   
    if (scanf("%d", &n) != 1) {
        return 0; 
    }

   
    for (int i = 1; i <= n; i++) {
        sum += (i * i); 

    
    printf("%d\n", sum);

    return 0;
}