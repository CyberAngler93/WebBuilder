#include "html5class.hpp"
#include <iostream>
#include <vector>
#include <memory>



int main(){
  std::string apple = "hello";
  std::string banna = "goodbye";

  Section b("Hi");
  std::cout << b << "\n";
  std::vector<std::string> myVector;
  for(int i = 1; i <= 20; i++){
    if(i % 2 == 1){
      myVector.push_back("Link");
    }
    else{
      myVector.push_back("Title");
    }
  }
Nav c(myVector);

  return 0;
}
