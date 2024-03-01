#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char c[100];
    int count = 0;
    FILE *fp = fopen("../LOTR.txt", "r");

    if (fp == NULL)       
        printf("error in opening file");


    while(fscanf(fp, "%s", c) != EOF){
        
        // printf("%s", c);
        for (int i = 0; c[i]; i++) {
            c[i] = tolower(c[i]);
        }
        int value = strcmp(c,"hobbit");
        if (!value)
        {
            count++;
        }
        
    }

    printf("%d", count);

    fclose(fp);
}