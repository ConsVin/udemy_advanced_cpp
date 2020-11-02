#include <iostream>
#include <vector>
  #include <stdio.h>

void printf(std::vector<std::vector<int>> grid_2D ){
	for (auto vec: grid_2D){
		for (auto i: vec){
	 		printf("%3d ",i);
		}
		printf("\n");
	}
}


int main(){
	std::vector<  std::vector< int>>  grid_2D = {{1},{1,2},{1,2,3},{1,2,3,4}};
	
	for (int i=0; i < grid_2D.size(); i++){
		for (int j=0; j < grid_2D[i].size(); j++){
			grid_2D[i][j] = (i+1)*(j+1) *2;
		}
	}
	printf(grid_2D);

	printf("Access by value:\n");
	for (auto vec: grid_2D){
		for (auto i: vec){
	 		i+=-1;
		}

	}
	printf(grid_2D);
	
	printf("Access by reference:\n");
	for (auto &vec: grid_2D){
		for (auto& i: vec){
	 		i/=2;
		}
	}
	printf(grid_2D);
	
	
	

	std::vector<double> vec_float = {1,2,3,4,5};


}
