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

int main(){

    Test x0;
    auto &&x2 = Test();
    auto &&x3 = x0;
    
    check(x2);
    check(x3);


    return 0;
}