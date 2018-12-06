/*This is the main operations for website builder made by Matt Perry and Tailon Russell
For cs202 Fall 2018
An auto html5 writing lib

*/

#include "html5Helperfunctions.hpp"
#include "html5class.hpp"
#include <iostream>
#include <sstream>
//#include "windows.h"



//main functions

int main()
{
	//declaration of our variables
	std::stringstream ss;
	std::ofstream writingIndex("index.html");
	std::vector<Nav> vectorNavs;
	std::vector<Section> vectorSections;
	std::string userInput;
	//introduction to the website
	std::cout << "Welcome to Web Builder!" << std::endl;
	std::cout << "This was created by Matt and Tailon" << std::endl;
	handleInputWithChecking(std::cin,"Enter the title of the website",userInput,3);
	Head userHead(userInput,"style.css");
	std::cout << "You may type help for a command list\n" << std::endl;
	std::cout << "You can type one three options: section, nav, or exit" << std::endl;
	std::cout << "A nav is where you can create tabs to different parts of your website known as sections" << std::endl;
	std::cout << "In a section you can write a paragraph or a insert an image" << std::endl;
	while(true){
		handleInputWithChecking(std::cin,"What would you like to do?",userInput,5);
	if(userInput == "nav"){
			makeNav(std::cin,ss,vectorNavs);
		}
		else if(userInput == "section"){
			makeSections(std::cin,vectorSections);
		}
		else if(userInput == "help"){
			std::cout << "Welcome to Web Builder!" << std::endl;
			std::cout << "This was created by Matt and Tailon" << std::endl;
			std::cout << "Commands include 'help' , 'exit' , 'head' , 'nav' and 'section'" << std::endl;
		}
		else if(userInput == "exit") {
			break;
		}
	}

	std::cout << "Your website is now being created!" << std::endl;

	print(writingIndex , userHead, vectorNavs, vectorSections);
	//ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);
	std::cout << "Hey its worked" << std::endl;
	return 0;
	}
