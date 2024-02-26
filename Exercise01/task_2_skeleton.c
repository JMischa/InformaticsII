#include <stdio.h>

void rleCompression(char string[], int length) {
    //Put your code here
    if (length == 0){
        return;
    }
    int counter = 1;
    char mostRecentChar = string[0];
    for (int i = 1; i < length; i ++) {
        if (mostRecentChar == string[i]){
            counter++;
        } else {
            printf("%d%c", counter, mostRecentChar);
            counter = 1;
            mostRecentChar = string[i];
        }
    }
    printf("%d%c", counter, mostRecentChar);
}

int main() {
    char string[] = "AAABBAAAA";
    int length = (sizeof(string) / sizeof(string[0])) - 1;
    rleCompression(string, length);
    return 0;
}
