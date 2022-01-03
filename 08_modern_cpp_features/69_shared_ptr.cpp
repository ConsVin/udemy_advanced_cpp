#include <iostream>
#include <memory>

class Rex{
public:
    int alpha;
    std::string Name{"Default"};
    Rex(){
        std::cout<<">>>> Constructor\n";
    }
    
    Rex(std::string s):Name(s){
    }

    ~Rex(){
        std::cout<<"------- Denstructor of "<<Name<<"\n";
    }
    
    void greet(){
        std::cout<< Name << " :: \tAnd for this act, may the god watch over you \n\
                      and treat you better than he treated me.  " << alpha <<"\n";
    }
    void greet_foo(){
        std::cout<<"\tAnd for this act, may the god watch over you \n\
                      and treat you better than he treated me.  " << alpha <<"\n";
    }

};


int main(){
    
    {   
        std::cout<<"Unique::\n";
        std::unique_ptr<Rex> pRex(  new  Rex());
    }

    std::cout<<"Create new :\n";
    std::shared_ptr<Rex> pRexGlbl(nullptr);
    std::cout<<"Greetings:\n";
    // Attempt to access Alpha leads to
    // pRexGlbl->greet(); bash: Segmentation fault  (core dumped) ./69_shared_ptr
    
    {
        std::shared_ptr<Rex> pRex( new Rex("pRex"));
        pRex->greet();
        pRexGlbl = pRex;

        // >> No Destructor call here <<
    }
    std::cout<<"Left the scope, but pRex still exsits";
    pRexGlbl->greet();


      {
        std::cout<<"Assign to global another pointer \n";
        std::shared_ptr<Rex> pRex2 = std::make_shared<Rex>("pRex2");
        pRexGlbl = pRex2;
        // Here destructor called for pRex object as it has no more references
    }
     std::cout<<"Left the scope, destructor for pRex was called \n";

    //And here it works fine
    pRexGlbl->greet();


}

