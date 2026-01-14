#include <stdio.h>

int get_height(void);

int main(void) {
    
    int height = get_height();
    
    for(int row = 0; row < height; row++) {
        for(int spaces = height - 1; spaces > row; spaces--) {
            printf(" ");
        }
          for(int col = -1; col < row; col++) {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void) {
    
    int height;
    
    do {
        printf("Height: ");
        scanf("%d", &height);
    } while(height < 0);
    
    return height;
}
