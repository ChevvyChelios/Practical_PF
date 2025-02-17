#include <stdio.h>
#include <string.h>

void sortString(char *str){
    int i, j;
    char temp;
    int n = strlen(str);
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(str[i] > str[j]){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    sortString(str);
    printf("The sorted string is: %s\n", str);
}