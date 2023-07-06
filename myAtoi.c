#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int powerTen (int n) {
    long int sum = 1;
    for (int i = 0 ; i < n ; i++) {
        sum = sum * 10;
    }
    return sum;
}

int  myAtoi (char *s) {
    int size = 0, signal = 1, k = 0, dim = strlen(s) + 1, count = 0, carry = 0, c = 0, j = 0, n = 0; // 1-positivo 0-negativo
    char *num = (char*)malloc(sizeof(char) * dim);
    long int  number = 0, p = 0;

    if ((s[0] < 48 || s[0] > 57) && s[0] != '-' && s[0] != '+' && s[0] != ' ') {
        printf("inicio\n");
        return 0;
    }
    for (int i = 0 ; i < strlen(s) ; i++) { 
        printf("%c %d %d\n", s[i], c, count);
        if (s[i] == '-' && c == 0)
            signal = 0;
        if (s[i] >= 48 && s[i] <= 57) {
            if (j == 0) {
                n = i;
                j = 1;
            }
            if (s[i] != '0')
                c = 1;
            num[k] = s[i];
            if (c == 1) {
                k++;
                size++;
            }
            carry = 1;
            //printf("num %c size %d\n", s[i], size);
        }
        else {
            if (carry == 1)
                break;
            if (s[i] != ' ')
                count++;
            if (c == 1)
                return 0;
        }
    }
    printf("n %d s[n] %c\n", n, s[n]);
    if (n > 0) {
       if (s[n-1] == '-' || s[n-1] == '+') {
        printf("kghns");
        n--;
    } 
    }
    for (int i = 0 ; i < n ; i++) {
        printf("s %c\n", s[i]);
        if (s[i] != ' ') {
            return 0;
        }
    }
    if (count > 1) {
        printf("count\n");
        return 0;
    }
    num[size] = '\0';
    if (size >= 11) {
        if (signal == 0) {
            return -2147483648;
        }           
        else if (signal == 1) {
            return 2147483647;
        }          
    }

    for (int i = size, k = 0 ; i > 0 ; i--, k++) {
        p = powerTen(i-1);
        number = number + (p * (num[k] - 48));
        //printf("number: %d power: %d size: %d unidade: %d\n", number, p, i, (int)(num[k] - 48));
    }
    if (signal == 0)
        number = number - (2 * number);
    if (number >= 2147483648) {
        return 2147483647;
    }
    if (number <= -2147483648)
        return -2147483648;
    printf("final\n");
    return number;
}
