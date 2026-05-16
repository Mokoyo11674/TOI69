#include <stdio.h>
#include <ctype.h> 
int main() {
    int n, count = 0;
    char c;

    
    if (scanf("%d", &n) != 1) return 0;

   
    for (int i = 0; i < n; i++) {
        
        scanf(" %c", &c);
        
        
        c = toupper(c); 
        
       
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}