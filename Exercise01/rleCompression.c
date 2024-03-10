#include <stdio.h>
#include <string.h>


void rleCompression(char string[], int length){
    char current = string[0];
    int counter = 1;
    char result[length * 2];
    result[0] = '\0';

    for(int i = 1; i <= length; i++){
        if(current == string[i]){
            counter++;
        }
        else{
            sprintf(result + strlen(result), "%d%c", counter, current);
            current = string[i];
            counter = 1;
        }
    }
    printf("compressed string: %s\n", result);
}


int main(){
    char string[] = "AAABBAAAA";
    int length = sizeof(string)/sizeof(string[0]) - 1;

    rleCompression(string, length);
    return 0;
}
