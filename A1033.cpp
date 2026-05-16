#include <stdio.h>

int main() {
    int n;
    int count = 0; 
    char ch;

    
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    
    for (int i = 0; i < n; i++) {
        
        scanf(" %c", &ch);

       
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++; 
    }


    printf("%d\n", count);

    return 0;
}