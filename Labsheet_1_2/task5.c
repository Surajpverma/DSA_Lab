#include <stdio.h>
int main(void)
{
    char c; 
    FILE *fp = fopen(__FILE__, "r");

    if (fp == NULL)       
        printf("error in opening file");

    do{
        c = fgetc(fp);
        putchar(c);
    }while(c!=EOF);

    fclose(fp);
}