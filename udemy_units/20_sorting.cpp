#include <iostream>
#include <vector>
#include <algorithm>


class Hero{
  public:
     int strength;
    int manna;
    int health;
    std::string name;


    Hero(std::string n, int s, int m, int h): name(n), strength(s), manna(m), health(h){}

    void print(){
      std::cout <<name<<" :   "
                << strength << " "
                << manna << " "
                << health<<"\n";
    }
};

bool comp(const Hero &a, const Hero &b) {
  if (a.strength == b.strength )
      if (a.manna == b.manna )
          return a.health < b.health;
      else
          return a.manna < b.manna ;
  else
    return a.strength < b.strength;
}

template<typename Container>
void print(const Container& cont) {
   for (auto const x : cont) {
    x.print();
   }
 
}


int main(){
 /*
  Hero A("Prometeus", 10,12,15);
  A.print();

  std::vector<Hero> heroes = { Hero("Prometeus",   2,12,15),
                               Hero("Hercueles",   10,11,23),
                               Hero("Hercueles_2", 10,15,23),
                               Hero("Hercueles_3", 10,15,23),
                               Hero("Perseus"    ,  8,13,7 )};
  std::cout<<"Before:\n";
  print(heroes);
  sort(heroes.begin(), heroes.end(), comp);
  std::cout<<"After:\n";
  print(heroes);
*/
}