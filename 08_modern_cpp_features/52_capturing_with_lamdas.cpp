#include <iostream>

class Hero{
private:
	int health {100};
	int manna {1000};
public:
	void heal(){
		health += 40;
		manna -= 50;

		int strength = 66;
		int harizma  = 99;
		// auto plambda = [harizma,strength,manna](){ << Manna is illegal here!
		
		auto plambda = [harizma,strength,this](){
			manna = -100;
			std::cout<< "Strength  " << strength <<"\n"
						"Manna   "   << manna    <<"\n" // Capture with This, by reference!!!
						"Harizma  " << strength  <<"\n";
		};


		auto plambda_foo = [=](){
			// manna = -100; << Illegal! Cathced by valud
			std::cout<< "Value Captured Manna   "   << manna    <<"\n" // Capture with This, by reference!!!
			;
		};

			

		auto plambda_boo = [&, this](){
			manna = -77; 
			std::cout<< "reference Captured Manna   "   << manna    <<"\n" // Capture with This, by reference!!!
			;
		};

		std::cout<<" === Heal Method=== \n";
		plambda();
		plambda_foo();
		plambda_boo();
		std::cout<<" ================== \n";
		
	}
	void damage(){
		health /= 2;
	}

	void print(){
		std::cout<<"H: "<< health << " M: "<< manna<<"\n";
	}
};

int main(){

	Hero bob;

	bob.heal();
	


}