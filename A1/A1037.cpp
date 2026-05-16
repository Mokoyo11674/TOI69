#include <stdio.h>

int main() {
    int x;

    
    if (scanf("%d", &x) != 1) {
        return 0;
    }

    
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    
    for (int i = 0; i < 13; i++) {
        
        while (x >= values[i]) {
            printf("%s", symbols[i]); 
            x -= values[i];           
        }
    }
    
    printf("\n"); 

    return 0;
}