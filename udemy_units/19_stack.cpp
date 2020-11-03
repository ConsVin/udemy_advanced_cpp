#include <iostream>
#include <stack>
#include <queue>

class Car{
	private:
		std::string vin;
		int          dist;
		short        year;
	public:
	void count_down(){
		year  = std::min(year + 5, 2020);
		dist /= 2;
	}
	Car (std::string v, int d, int y):vin(v),dist(d), year(y){}
	~Car() {}


	void print(){
		std::cout<<"Car :"<< vin<< " "<< dist << " " << year<<"\n";
	}
};

int main(){
	Car Lastochka("AFDN-3232-AA",23000,2007);

	std::stack<Car> jam,jam_2;

	for (int year=1998; year<2020; year+=3){
		jam.push(Car("AFFGD-433-ADFF", 132+666*(year-1998), year));
	}

	 while (!jam.empty()) 
    { 
      	auto i_car = jam.top();
      	i_car.print();
      	i_car.count_down();
        jam_2.push(i_car);
        jam.pop();
    } 

    std::cout<<"Upgraded :=)\n";
	 while (!jam_2.empty()) 
    { 
      	jam_2.top().print();
        jam_2.pop();
    } 


}
