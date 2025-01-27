#include<stdio.h>
#include<ctype.h>

int main(){
    FILE* fp;
    char file[20];
    printf("Enter name: ");
    scanf("%s", file);
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Could not open file %s", file);
        return 1;
    }
    char ch;
    int count = 0;
    while((ch = fgetc(fp)) != EOF){
        if(!isspace(ch))
            count++;
        // printf("%c", ch);
    }

    printf("size = %d\n", count);
    fclose(fp);
    return 0;
}