#include <stdio.h>
int main(void)
{
    char c;
    FILE *fp1 = fopen("msg.txt", "r+");
    FILE *fp2 = fopen("target.txt", "w");

    if (fp1 == NULL)       
        printf("error in opening file1");
    if (fp2 == NULL)       
        printf("error in opening file2");

    do{
        c = fgetc(fp1);
        fputc(c, fp2);
    }while(c!=EOF);

    fclose(fp1);
    fclose(fp2);
}