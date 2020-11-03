#include <iostream>
#include <stack>
#include <queue>


template<typename Container>
void print(std::string header, const Container& cont) {
   std::cout <<header<<" : ";
   for (auto const& x : cont) {
      std::cout << x << " ";
   }
   std::cout << '\n';
}

int main(){

	std::stack<int> S;
	std::queue<int> Q;

	for (int i=0; i<13; i++){
		std::cout<<"Add "<< i <<"\n";
		S.push(i);
	}
	
	for (int i=0; i<5; i++){
		std::cout <<" Get from Stack :" 
				  << S.top() <<" and move to queue \n";
		Q.push(S.top());
		S.pop();
	}
	std::cout <<" Size of stack :" << S.size()  << "\n";
	std::cout <<" Size of queue :" << Q.size() << "\n";
	
	
	while(!Q.empty()){
		std::cout<< "Front element"   << Q.front()
				 << " Back element : "<< Q.back()  << "\n";
		Q.pop();
	}
	
}
