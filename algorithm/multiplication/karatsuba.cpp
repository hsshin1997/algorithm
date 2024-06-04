#include<iostream>
#include<stdio.h>
#include<cmath>
#include <ctime>

using namespace std;

int countDigit(int a);
int multiply(int a, int b);

int main() {
    int x, y;

    // Input the integers to be multiplied
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;

    // Perform the multiplication using Karatsuba algorithm
    int result = multiply(x, y);

    // Output the result
    cout<<"Classical Algorithm : " <<endl;
    const clock_t classical_time = clock();
    cout << "Result of multiplication: " << x*y << endl;
    cout << float( clock () - classical_time ) /  CLOCKS_PER_SEC<<endl<<endl;

    cout<<endl<<"Karatsuba Algorithm : "<<endl;
    const clock_t karatsuba_time = clock();
    cout << "Result of multiplication: " << result << endl;
    cout << float( clock () - karatsuba_time ) /  CLOCKS_PER_SEC<<endl<<endl;

    return 0;
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
    int numDigit = max(countDigit(num1), countDigit(num2));

    if (num1 < 10 || num2 < 10) {
        return num1*num2;
    } else {
        int nHalved = numDigit/2;
        int scale = pow(10, nHalved);
        int a = num1 / scale;
        int b = num1 % scale;
        int c = num2 / scale;
        int d = num2 % scale; 
        
        int p = a + b;
        int q = c + d;

        int ac = multiply(a, c);
        int bd = multiply(b, d); 
        int pq = multiply(p, q); 

        int adbc = pq - ac - bd;

        return pow(10, nHalved*2)*ac + scale*adbc + bd; 
    }
}