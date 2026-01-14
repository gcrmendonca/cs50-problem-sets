#include <stdio.h>

long user_input(void);

int main(void) {
    
    long card = user_input();

    int lenght = 0;
    long temp_card = card;
    
    while(temp_card > 0) {
        temp_card /= 10;
        lenght++;
    }
    
    if(lenght != 13 && lenght != 15 && lenght != 16) {
        printf("INVALID\n");
        return 0;
    }
    
    int sum1 = 0, sum2 = 0, total = 0;
    long mod1, mod2, d1, d2;
    temp_card = card;
    
    while (temp_card > 0) {
        //for the last && alternate values
        mod1 = temp_card % 10;
        sum1 += mod1;
        temp_card /= 10;  // goes to the second last digit of the card number
        
        //for last second and alt values && add number*2 digits
        mod2 = temp_card % 10;
        mod2 *= 2; // its the number times 2 6*2 = 12
        d1 = mod2 / 10; // 12/10 = 1.2 == 1
        d2 = mod2 % 10; // 12/10 = 1.2 == 2
        sum2 += d1 + d2;
        
        // to remove the second last value
        temp_card /= 10;
    }
    
    total = sum1 + sum2;
    
    if(total % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }
    else {
        long start = card;
        
        while(start >= 100) {
            start /= 10;
        }
        
        if((lenght == 13 || lenght == 16) && (start / 10 == 4)) {
            printf("VISA\n");
        }
        else if (lenght == 15 &&(start == 34 || start == 37)) {
            printf("AMEX\n");
        }
        else if(lenght == 16 &&(start > 50 && start < 56)) {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    
}
    
long user_input(void) {
    long user_input;
    do {
        printf("Number: ");
        scanf("%ld", &user_input);
        printf("\n");
    }  while(user_input < 0);
    
    return user_input;
}



