#include <iostream>
#include <vector>
using namespace std;

class A {

public:

void func(){}

};

class B:public A {

public:

int i;

};

class C {

public:

virtual void func(){}

};

class D:public C {

public:

char i;

};

int main() {

printf("sizeof A: %d\n", sizeof(A));

printf("sizeof B: %d\n", sizeof(B));

printf("sizeof C: %d\n", sizeof(C));

printf("sizeof D: %d\n", sizeof(D));

printf("sizeof A[10]: %d\n", sizeof(A[10]));

}