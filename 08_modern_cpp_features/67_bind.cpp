#include <iostream>
#include <functional>

using namespace std::placeholders; // _2,_1,_3

auto add (int a, int b, int c){
    std::cout<<" A: " << a << " B : " << b <<" C: "<< c <<"\n";
    return a + b + c;
}

void run(std::function<int(int,int)> func){
    func(77,33);
}


template <typename T>
class Tiresias{
public:

    T alpha = 42;
// Keyword Static let you call function from calss, not from the object
// Static means "Related to Class, not to the object"
  static auto add(T a, T b, T c ){ 
        auto R =  a+b+c;
        std::cout<<"Tiresias: A: " << a << " B : " << b <<" C: "<< c <<" = " << a+b+c << "\n";
        return R;
    }

    auto mult(T a, T b ){ 
        auto R =  a*b*alpha;
        std::cout<<"Mult: A: " << a << " B : " << b <<" Alpha: "<< alpha <<" = " << R << "\n";
        return R;
    }


};

int mult2(int x){
        return x*2;
}
int main(){
    std::cout << add(2,3,4) << "\n";

    auto calc = std::bind( &add, 5,10,20);
    auto calc_2 = std::bind( &add, 5,_1, 20);

    auto r = calc();
    std::cout<<" calc() return "<<r<<"\n";
    std::cout<<" calc_2() return "<<calc_2(8)<<"\n";

    auto calc_zoo = std::bind( &add, _3,_1, _2);
    std::cout<<" calc_zoo() return "<<calc_zoo(1,2,3)<<"\n";

    // Use constants or args or any other     
    const auto FIVE = 5;

    auto calc_foo = std::bind( &add, FIVE ,_2, _1);
    std::cout<<" calc_foo() return "<<calc_foo(10,20)<<"\n";
    run(calc_foo); // Five from const, 77 abd 33 frin void run()


    // Call Static function of class
    Tiresias<int>::add(10,20,30);
    auto call_Tiresias = std::bind( Tiresias<int>::add, 1000,_2,_1);
    call_Tiresias(5,10);
    
    // Call non-static method from obkect
    Tiresias<int> mythic;
    mythic.alpha=1000;
    auto call_mythic = std::bind( &Tiresias<int>::mult, mythic, _2,_1);
    call_mythic(33,1);
    

}