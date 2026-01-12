#include <stdio.h>

int get_height(void);

int main(void) {
    
    int height = get_height();
    
    for(int row = 0; row < height; row++) {
        for(int spaces = height - 1; spaces > row; spaces--){
            printf(" ");
        }
        for(int col = -1; col < row; col++) {
            printf("#");
        }

        printf("  ");
        
        for(int col2 = -1; col2 < row; col2++) {
            printf("#");
        }
            
        printf("\n");
    }
    
    return 0;
}

int get_height(void) {
    
    int height;
    
    do {
        printf("Insert the height: ");
        scanf("%d", &height);
    } while(height < 0 || height == 0 || height > 8);
    
    return height;
}
