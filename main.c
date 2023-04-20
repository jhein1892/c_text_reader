// Implement a basic command-line application that reads data from a text file and performs operations such as word count, and character count.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    FILE *fp;
    char buffer[1000];
    fp = fopen("test.txt", "r");
    int characters = 0;
    int non_letter = 0;
    int letter = 0;
    int words = 0;
    int lines = 0; 

    if (fp == NULL){
        printf("Error opening File\n");
        return 0;
    }

    while (fgets(buffer, 1000, fp)){
        ++lines;
        characters += strlen(buffer);
        char *token = strtok(buffer, " \n\r\t");
        while(token != NULL){
            ++words;
            int len = strlen(token);
            for (int i = 0; i < len; ++i){
                if (isalnum(token[i])){
                    letter++;
                } else {
                    non_letter++;
                }
            }
            token = strtok(NULL, " \n\r\t");
        }
        
    }

    fclose(fp);

    printf("Lines: %d\nWords: %d\nLetters/Numbers: %d\nNon-AlphaNum Characters: %d\nTotal Char: %d", lines, words, letter, non_letter, characters);

    return 0;
}