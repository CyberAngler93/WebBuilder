#include "html5class.hpp"
#include <iostream>
#include <vector>
#include <memory>



int main(){
  std::string apple = "hello";
  std::string banna = "goodbye";
  std::unique_ptr<HTML> a = std::make_unique<Head>(banna,apple);
  //a.setTitle("hello");
  //std::cout << a << "\n";
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
std::cout << c << "\n";
std::vector<std::unique_ptr<HTML>> myHtmlObjects;
myHtmlObjects.push_back(a);
//myHtmlObjects.push_back(b);
//myHtmlObjects.push_back(c);
//Head d = myHtmlObjects[0];

//std::cout << d ;
  //auto  & c = myHtmlObjects[0];
  //std::cout << c << "\n";



  return 0;
}
