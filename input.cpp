#include <iostream>

using namespace std;

int add_something(int x, int y) {
    cout << "casually adding some stuff together" << endl;
    int z = x + y;
    return z;
}

void print_something_fancy(int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "#";
        }
        cout << endl;
    }
}

int fibonacci(int n) {
    if (n < 0) {
        cout << "Incorrect input" << endl;
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    cout << "Okay, lets go..." << endl;
    int x = add_something(5, 4);
    cout << "taking the result and printing something fancy with it..." << endl;
    print_something_fancy(x);
    cout << "doing the fibonacci of " << 35 << "..." << endl;
    cout << fibonacci(35) << endl;
    return 0;
}