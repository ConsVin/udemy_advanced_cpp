#include <iostream>
using namespace std;

class Test{

};


void check(const Test &x){
    std::cout<<"L-Value \n";
}

void check(const Test &&x){
    std::cout<<"R-Value \n";
}

//-- Template will be prefered over function
template <typename T>
void call_cast (T &&arg){
    std::cout<<"Template Call\n";
    check(static_cast<T>(arg));
}

template <typename T>
void call (T &&arg){
    std::cout<<"Template Call\n";
    check((arg));
}




int main(){

    Test x0;
    auto &&x2 = Test();
    auto &&x3 = x0;

    std::cout<<"===========\n";
    check(x2); // L
    check(x3); // L
    call(x2);  // L
    call(x3);  // L
    std::cout<<"===========\n";
    call(Test()); // L
    call(x0);     // L
    std::cout<<"===========\n";
    call_cast(Test()); // R
    call_cast(x0);// L





    return 0;
}