#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void) {

//    Prompt the user for some text
    char text[1000];

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

// Count the number of letters, words, and sentences in the text

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

//    Compute the Coleman-Liau index

    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);


//    Print the grade level

    if (rounded_index > 1 && rounded_index < 16) {
        printf("Grade %d\n", rounded_index);
    } else if (rounded_index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Before Grade 1\n");
    }

    return 0;
}

int count_letters(char *text) {
    long lenght = strlen(text);
    int count = 0;

    for (int i = 0; i < lenght; i++){
        if (isalpha(text[i])) count++; // verifies if is alpha numeric || letters
    }
    return count;
}

 int count_words(char *text) {
     long lenght = strlen(text);
     int count = 0;

     char non_words[] = " ,.\n\t\""; // usualy separate words

     for (int i = 0; i < lenght; i++){
         while (i < lenght) {
             if (strchr(non_words, text[i]) != NULL)// verifies if the char position has a non_words char and breaks if it has and increments count
                 break;
             i++;
         }

         count++;

         while (i < lenght) {
             if (strchr(non_words, text[i]) == NULL)
                 break;
             i++;
         }
     }

     return count;
 }

 int count_sentences(char *text) {
     long lenght = strlen(text);
     int count = 0;
     char sentences_end[] = "!?.";

     for (int i = 0; i < lenght; i++) {
         while (i < lenght) {
             if (strchr(sentences_end, text[i]) != NULL)
                 break;
             i++;
         }

         count++;

         while (i < lenght) {
             if (strchr(sentences_end, text[i]) == NULL)
                 break;
             i++;
         }
     }

     return count;
 }
