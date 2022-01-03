#include <iostream>
#pragma pack(4)
struct S{
		char   a;
		char   b;
		int    i;
		short  j;
		double k;
	long long  l;
};

struct Person_B {
    char name[50];
    int age;
    double weight;
};


#pragma pack(1)
struct T{
	char   a;
	char   b;
	int    i;
	short  j;
	double k;
	long long  l;
};

#pragma pack(push, 2)
struct Person_A {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main(){
	std::cout << " Size of Person_A "<< sizeof(Person_A) << std::endl;
	std::cout << " Size of Person_B "<< sizeof(Person_B) << std::endl;
	printf("\nOffset Of S:\n");
	printf("S.a %zu \n", offsetof(S, a));
	printf("S.b %zu \n", offsetof(S, b));
	printf("S.i %zu \n", offsetof(S, i));
	printf("S.j %zu \n", offsetof(S, j));
	printf("S.k %zu \n", offsetof(S, k));
	printf("S.l %zu \n", offsetof(S, l));
	
	printf("\nOffset Of T:\n");
	printf("T.a %zu \n", offsetof(T, a));
	printf("T.b %zu \n", offsetof(T, b));
	printf("T.i %zu \n", offsetof(T, i));
	printf("T.j %zu \n", offsetof(T, j));
	printf("T.k %zu \n", offsetof(T, k));
	printf("T.l %zu \n", offsetof(T, k));



}