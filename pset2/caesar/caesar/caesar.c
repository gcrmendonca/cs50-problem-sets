#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

    // get a key
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    long len = strlen(argv[1]);
    
    
    for (int i = 0; i < len; i++) {
        
        if (isalpha(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
           
    int key = atoi(argv[1]);
    
    if (key < 0 || key > 99) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    printf("key: %d\n", key);

    // get plaintext
    
    char text[1000];
    
    printf("Plaintext:  ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    // enceipher
    // 𝑐𝑖=(𝑝𝑖+𝑘)⁢ % ⁢26
    // 𝑐𝑖 == iˆth character of the ciphertext
    // 𝑝𝑖 == iˆth character of the plain text
    // k == key
    
    // convert ASCII to alphabetical index
    long lenght = strlen(text);
    
    char cipher_text[1000];
    char non_cipher[] = " ,.\n\t!?\"";
    
    for (int i = 0; i < lenght; i++) {
        int index = text[i];
        int ci = 0;

        if (isalpha(text[i])) {
            if (islower(text[i])) {
                index -= 'a';
                
                ci = (index + key) % 26;
                cipher_text[i] = ci + 'a';
                
            } else if (isupper(text[i])) {
                index -= 'A';
                
                ci = (index + key) % 26;
                cipher_text[i] = ci + 'A';
            }
        }
        else {
            cipher_text[i] = text[i];
        }
                
    }
    
    cipher_text[lenght] = '\0';
    
    // print ceiphertext
    printf("Ciphertext: %s\n", cipher_text);
    
    
    
    return 0;
}
