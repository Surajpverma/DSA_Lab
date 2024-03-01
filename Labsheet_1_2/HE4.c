#include <stdio.h>
#include<string.h>
#include <ctype.h>


char decode(char* morse[], char characters[],char word[]){
    for(int i = 0; i < 26; i++){
        if(strcmp(word, morse[i]) == 0)
            return characters[i];
    }
    return '!';
}

int main(void)
{
    char c[100];
    char* morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
        ".----", "..---", "...--", "....-", ".....",
         "-....", "--...", "---..", "----.", "-----" 
    };

    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    FILE *fp = fopen("../msg.txt", "r");

    if (fp == NULL)       
        printf("error in opening file");

    while(fscanf(fp, "%s", c) != EOF){
        char decodedWord = decode(morse, characters, c);
        printf("%c", decodedWord);
    }
    
    fclose(fp);
}