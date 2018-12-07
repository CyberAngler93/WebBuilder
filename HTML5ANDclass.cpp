/*This is the main operations for website builder made by Matt Perry and Tailon Russell
An auto html5 writing lib

*/

#include "html5Helperfunctions.hpp"
#include "html5class.hpp"
#include <iostream>
#include <sstream>
//uncomment this if you are on a windows machine.
//#include <windows.h>



//the main formula

int main()
{
	//declaration of our variables
	std::stringstream ss;
	std::ofstream writingIndex("index.html");
	std::vector<Nav> vectorNavs;
	std::vector<Section> vectorSections;
	std::string userInput;
	std::string userColor = "";
	std::string userImage = "";

	//introduction to the website
	std::cout << "Welcome to Web Builder!" << std::endl;
	std::cout << "This was created by Matt and Tailon" << std::endl;
	//first user prompt for what the background of the page should have.
	handleInputWithChecking(std::cin,"Would you like an image or just color for a background?",userInput,6);
	//handling the users input to store the information
	if(userInput == "color"){
		handleInputWithChecking(std::cin,"Enter a color!",userColor,7);
	}else if(userInput == "image"){
		handleInputWithChecking(std::cin,"Enter a link to an image",userImage,3);
	}
	//second prompt for user inptu on a website title this goes in the head tag and makes the tab have a title.
	handleInputWithChecking(std::cin,"Enter the title of the website",userInput,3);
	//hard coded the style.css sheet into the passing of the constructor of head, if user wants own style lib change here.
	Head userHead(userInput,"style.css");
	//user interaction to help guide the user in can be done!
	std::cout << "You may type help for a command list" << std::endl;
	std::cout << "You can type one three options: section, nav, or exit" << std::endl;
	std::cout << "A nav is where you can create tabs to different parts of your website known as sections" << std::endl;
	std::cout << "In a section you can write a paragraph or a insert an image" << std::endl;
	//begin the main loop of creating the page. this allows the user to run for as long as they would like!
	while(true){
		//asking for input
		handleInputWithChecking(std::cin,"What would you like to do?",userInput,5);
		//a couple clauses for what the user enters.
	if(userInput == "nav"){
		//askng the user if they would like to link the nav to a section. This code was put here so we could access all the current section objects for titles.
		handleInputWithChecking(std::cin,"Would you like to link this nav to a section?",userInput,1);
		if(userInput == "y"){
			//range based loop dumping out the titles of all our sections
			for(auto i : vectorSections){
				std::cout << i.getSectionTitle() << " ";
			}
			std::cout << "\n";
			std::cout << "You must enter one name from these sections you created for each tab you will create" << std::endl;
		}
			//this is pushing a empty section to the vector of sections as a method to allow the user to have control of where they want the sections and navs to appear
			Section secy;
			vectorSections.push_back(secy);
			//makeNav passing our user parameters!
			makeNav(std::cin,ss,vectorNavs);
		}
		else if(userInput == "section"){
			//used to keep the length of nav and section vectors the same.
			Nav navy;
			vectorNavs.push_back(navy);
			//make section taking the vector of sections by ref and the input
			makeSections(std::cin,vectorSections);
		}
		//if help is inputed we should help!?
		else if(userInput == "help"){
			std::cout << "Welcome to Web Builder!" << std::endl;
			std::cout << "This was created by Matt and Tailon" << std::endl;
			std::cout << "Commands include 'help' , 'exit' , 'nav' and 'section'" << std::endl;
		}
		//if they exit maybe we should ask, if they are sure.
		else if(userInput == "exit") {
			break;
		}
	}


	std::cout << "Your website is now being created!" << std::endl;

	print(writingIndex , userHead, vectorNavs, vectorSections,userColor,userImage);
	//you can uncomment this out if you are on windows
	//ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);
	//you can uncomment this out if you are linux and have google chrome!
	//system("google-chrome index.html");
	return 0;
	}
