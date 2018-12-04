#include "html5class.hpp"
#include <iostream>
#include <vector>




int main(){
  std::string apple = "hello";
  std::string banna = "goodbye";
  Head a(banna,apple);
  a.setTitle("hello");
  std::cout << a << "\n";
  Section b("Hi");
  std::cout << b << "\n";
  std::vector<std::string> myVector;
  for(int i = 0; i <= 20; i++){
    if(i % 2 == 1){
      myVector.push_back("Title");
    }
    else{
      myVector.push_back("Link");
    }
  }
  Nav c(myVector);
  std::cout << c << "\n";





  return 0;
}
