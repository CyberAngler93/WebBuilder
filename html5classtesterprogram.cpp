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






  return 0;
}
