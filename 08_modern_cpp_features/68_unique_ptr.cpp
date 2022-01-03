#include <iostream>
#include <memory>

class Rex{
public:
    Rex(){
        std::cout<<">>>> Constructor\n";
    }
    ~Rex(){
        std::cout<<"------- Denstructor\n";
    }
    
    void greet(){
        std::cout<<"\tAnd for this act, may the god watch over you \n\
                      and treat you better than he treated me. \n";
    }
};

class Laius{
private:
    // std::unique_ptr<Rex[]>  pArrRex(new Rex[3]) ; << NOT ALLOWED!
     std::unique_ptr<Rex[]>  pArrRex;
public:
    Laius():pArrRex(new Rex[3] ){
    }
    Rex get(int i){
        return pArrRex[i];
    }

};

int main(){
    {
        Rex Oedipus;
        std::unique_ptr<Rex> pRex( new Rex ); // When pRex go out of scope, it will be deallocated automatically
        Rex * pRexRaw = new Rex(); // This memory will not be deallocated
        Oedipus.greet();

    }
    std::cout<<" Above :: 3 constructors were called, but only 2 destructors, raw pointer left \n\n\n";

    {
        Rex * pRexRaw = new Rex(); 
        pRexRaw->greet();
        delete pRexRaw;
    }
    std::cout<<" Above :: 1 and 1 destructor were called \n\n";

    {   
        std::cout<<"Create Array of Rexes\n";
        std::unique_ptr<Rex[]>  pArrRex( new Rex[3]) ;
    }

    std::cout<<" Call Laius :\n";

    Laius L;
    Rex Od;
    L.get(0) = Od;

}

