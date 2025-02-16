#include <iostream>

using namespace std;

// Function prototypes for referencing:
void fnB(int n);

// int x = 0;

int fun(int n) {
    int static x = 0;

    if(n > 0) {
        cout << "in fun(): x=" << x << " n: " << n << endl;
        x++;
        return fun(n - 1) + x;
    }

    return 0;
}

void fnA(int n) {
    if(n > 0) {
        cout << "funA() n: " << n << endl;
        fnB(n - 1);
    }
}

void fnB(int n) {
    if(n > 0) {
        cout << "funB() n: " << n << endl;
        fnB(n / 2);
    }
}

int main(int argc, char** argv) {
    int r = 5;
    fun(r);
    cout << "run1: " << r << endl;

    fun(r);
    cout << "run2: " << r << endl;

    cout << endl << "Multiple recursion:" << endl;
    fnA(20);

    return 0;
}