#include <stdio.h>

int cauculate_quarters(int cents);
int cauculate_dimes(int cents);
int cauculate_nickels(int cents);
int cauculate_pennys(int cents);

int main(void) {
    int cents;
    do {
        printf("Change owed: ");
        scanf("%d", &cents);
    } while(cents < 0);
    
    if(cents == 0) {
        printf("no change needed\n");
        return 1;
    }
   
    int quarters = cauculate_quarters(cents); //calculate how much quarters to give to the customer
    cents -= quarters * 25; //subtracts the value of those quarters from cents
    
    int dimes = cauculate_dimes(cents);
    cents -= dimes * 10;
    
    int nickels = cauculate_nickels(cents);
    cents -= nickels * 5;
    
    int pennys = cauculate_pennys(cents);
    cents -= pennys * 1;
    
    printf("quarters: %d dimes: %d nickels: %d pennys: %d\n", quarters, dimes, nickels, pennys);
    
    return 0;
}



int cauculate_quarters(int cents) {
    int quarters = 0;
    while(cents >= 25) {
        quarters++;
        cents -= 25;
    }
    return quarters;
}
int cauculate_dimes(int cents) {
    int dimes = 0;
    while(cents >= 10) {
        dimes++;
        cents -= 10;
    }
    return dimes;
}
int cauculate_nickels(int cents) {
    int nickels = 0;
    while(cents >= 5) {
        nickels++;
        cents -= 5;
    }
    return nickels;
}
int cauculate_pennys(int cents) {
    int pennys = 0;
    while(cents >= 1) {
        pennys++;
        cents -= 1;
    }
    return pennys;
}
