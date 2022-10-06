#include <iostream>
#include "HelloWorld.h"

using namespace std;

std::string PrintHelloWorld(){
    return "Hello World";
}

int main(){
    std::cout << PrintHelloWorld() << '\n';
    return 0;
}