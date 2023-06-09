#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

    FILE *fp;
    char buffer[1000];
    fp = fopen("test.txt", "r"); // Swap out this filename for txt file in this directory
    int characters = 0;
    int non_letter = 0;
    int letter = 0;
    int words = 0;
    int lines = 0; 

    if (fp == NULL){
        printf("Error opening File\n");
        return 1;
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