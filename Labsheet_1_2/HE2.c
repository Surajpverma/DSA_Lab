#include <stdio.h>
#include <stdlib.h>

typedef struct metadata
{
    char name[20];
    int age;
    char address[50];
} Metadata;

void print(Metadata data){
    printf("%s\n", data.name);
    printf("%d\n", data.age);
    printf("%s\n", data.address);
}

int main(){
    int n = 0;
    printf("enter size of array: ");
    scanf("%d", &n);
    Metadata* data = (Metadata*) malloc(n * sizeof(Metadata));

    if (data == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1; 
    }

    for (int i = 0; i < n; ++i)
    {   
        char naam[20];
        char pta[50];
        scanf("%s %d %s", data[i].name, &data[i].age, data[i].address);
        
    }

    print(data[0]);

    free(data);
    
    return 0;
}