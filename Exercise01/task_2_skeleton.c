#include <stdio.h>

void rleCompression(char string[], int length) {
    //Put your code here
}

int main() {
    char string[] = "AAABBAAAA";
    int length = (sizeof(string) / sizeof(string[0])) - 1;
    rleCompression(string, length);
    return 0;
}
