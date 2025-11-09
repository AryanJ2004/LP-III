#include <iostream>
using namespace std;

int recursiveSteps = 0;
int fibRecursive(int n) {
    recursiveSteps++; 
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int iterativeSteps = 0;
int fibIterative(int n) {
    if (n <= 1) {
        iterativeSteps++;
        return n;
    }
    int a = 0, b = 1, c=0;
    for (int i = 2; i <= n; i++) {
        iterativeSteps++;
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    recursiveSteps = 0;
    int rec = fibRecursive(n);
    cout << "\nRecursive Fibonacci(" << n << ") = " << rec << endl; //TC: O(2^n), SC: O(n)
    cout << "Recursive Step Count = " << recursiveSteps << endl;

    iterativeSteps = 0;
    int itr = fibIterative(n);
    cout << "Iterative Fibonacci(" << n << ") = " << itr << endl; //TC: O(n), SC: O(1)
    cout << "Iterative Step Count = " << iterativeSteps << endl;
    return 0;
}
