#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    // get a key
    
    int key = argc;
    
    if (argc == 1) {
        printf("Usage: ./caesar key\n");
    }
    
    long len = strlen(*argv);
    
    for (int i = 0; i < len; i++) {
        if (isalpha(*argv[i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    // get plaintext
    // enceipher
    // print ceiphertext
    
    
    
    return 0;
}
