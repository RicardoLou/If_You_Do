#include <iostream>
#include "MyClass.h"
using namespace std;

MyClass::MyClass(){
	cout << "MyClass::MyClass()" << endl;
}

MyClass::~MyClass(){
	cout << "MyClass::~MyClass()" << endl;
}

void MyClass::print() {
	cout << "MyClass::print()" << endl;
}

int main() {
	MyClass obj;
	obj.print();
	return 0;
}