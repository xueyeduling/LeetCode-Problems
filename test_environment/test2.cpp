#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class A {
    public:
    int i = 1;
};

class B {
    public:
    int i = 2;
};

class C: public A, public B {
    public:
    int i = 3;
};

int main() {
    C* clsC = new C();
    A* clsA = clsC;
    B* clsB = clsC;

    cout << &(*clsA) << endl;
    cout << &(*clsB) << endl;
    cout << &(*clsC) << endl;

    cout << clsA->i << endl;
    cout << clsB->i << endl;
    cout << clsC->i << endl;

    return 0;
}