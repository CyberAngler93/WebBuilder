//Helper functions declarations

#ifndef HTML5HELPERFUNCTIONS_HPP_INCLUDED
#define HTML5HELPERFUNCTIONS_HPP_INCLUDED
#include "html5class.hpp"
#include <iostream>
#include <sstream>
//this is handleinput checking for numbers! if oyu want a number from the user lets use this!
void handleInputWithChecking(std::istream & is,std::stringstream & ss, std::string question, int & userAnswer);
//this is the error checking function that takes an inputstream, question, string you need answer in, and type of question. feel free to add more types to questions
void handleInputWithChecking(std::istream & is, std::string question, std::string & userAnswer,int typeOfQuestion);
void makeSections(std::istream & is, std::vector<Section> & sections);
//Make nav fucntion when you want to make a nav call this in main!
void makeNav(std::istream & is,std::stringstream & ss,std::vector<Nav> & navs);
//this is the print function defined for outputing our objects to an ofstream
//needs some tweaking to get rocking and rolling
void print(std::ostream & os,Head & head,std::vector<Nav> & nav, std::vector<Section> & sec);

//void setSectionTagParameter(Section &);

#endif
