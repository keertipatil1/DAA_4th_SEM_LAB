#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[1000];

void ShiftTableComputation(char p[]) {
    int m = strlen(p);
    for (int i = 0; i < 1000; i++) {
        table[i] = m;  
    }
    for (int j = 0; j < m - 1; j++) {
        table[(unsigned char)p[j]] = m - 1 - j;
    }
}

int HPoolStringMatching(char p[], char t[]) {
    int m = strlen(p);
    int n = strlen(t);
    ShiftTableComputation(p);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && t[i - k] == p[m - 1 - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i += table[t[i]];  
        }
    }
    return -1;
}

int main() {
    char str[100], ptr[100];
    int res;
    printf("Enter the text: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter pattern: ");
    fgets(ptr, sizeof(ptr), stdin);

    
    str[strcspn(str, "\n")] = '\0';
    ptr[strcspn(ptr, "\n")] = '\0';

    res = HPoolStringMatching(ptr, str);
    if (res == -1) {
        printf("Not found\n");
    } else {
        printf("Pattern found at position %d\n", res + 1);
    }
    return 0;
}
