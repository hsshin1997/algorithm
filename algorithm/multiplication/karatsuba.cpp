#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int multiply(int a, int b);
int countDigit(int a);

int main() {

}

int countDigit(int num) {
    if (num == 0 ) return 1;

    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int multiply(int num1, int num2) {
    int numDigit1 = countDigit(num1);
    int numDigit2 = countDigit(num2);
    
    int numDigit = max(countDigit(num1), countDigit(num2));

    if (numDigit == 1) {
        return num1*num2;
    } else {
        int a = num1 / pow(10, numDigit/2);
        int c = num2 / pow(10, numDigit/2); 

    }

    return 1;
}