/*This is the main operations for website builder made by Matt Perry and Tailon Russell
For cs202 Fall 2018
An auto html5 writing lib

*/



#include "html5class.hpp"
#include <iostream>

//declaration of our variables
std::ofstream writingIndex("index.html");
std::vector<Nav> navs;
std::vector<Section> sections;
std::vector<std::string> vectOfTabs;
std::string title;
std::string link;
std::string command;
std::string yOrN;
std::string phrase;
int numOfTabs;

//this is the print function defined for outputing our objects to an ofstream
//needs some tweaking to get rocking and rolling

void print(std::ostream & os,Head & head,std::vector<Nav> & nav, std::vector<Section> & sec){
	int navLen = nav.size();
	int secLen = sec.size();
	os << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>\n";
	head.print(os);
	for(int i = 0; i < navLen; i++){
		nav[i].print(os);
	}
	for(int i = 0; i < secLen; i++){
		sec[i].print(os);
	}
	os << "we doin it" << std::endl;

}


//main functions

int main()
{
	//introduction to the website
	std::cout << "Welcome to Web Builder!" << std::endl;
	std::cout << "Enter the title of the website" << std::endl;
	//switching this to getline so that we can have spaces in the title of our website?
	getline(std::cin, title);
	std::cout << "Enter the filepath of the css file" << std::endl;
	getline(std::cin, link);
	Head userHead(title, link);
	Section userFirstSection(title);
	sections.push_back(userFirstSection);
	std::cout << "Would you like to make a section?(y/n)" << std::endl;
	//while loop for error checking on the input from users becasue users are mean.
	while(true){
		getline(std::cin,command);
		if(command == "y" || command == "n"){
			break;
		}
		else{
			std::cout << "there was an error in your input please enter ('y'/'n')" << std::endl;
		}
	}

	while (command == "y")
	{
		std::cout << "What is the title of the section?" << std::endl;
		getline(std::cin, title);
		Section a(title);
		std::cout << "Do you want a paragraph or image in this section?" << std::endl;
		while (true) 
		{
			getline(std::cin, yOrN);
			if (yOrN == "paragraph" || yOrN == "image") 
			{
				break;
			}
			else {
				std::cout << "there was an error in your input please enter ('y'/'n')" << std::endl;
			}
		}
		if (yOrN == "paragraph")
		{
			std::cout << "Enter exit when you are done entering your paragraph" << std::endl;
			while (getline(std::cin, phrase))
			{
				if (phrase == "exit")
				{
					if (phrase == "exit")
					{
						break;
					}
				}
				else
				{
					a.setParagraph(phrase + " ");
				}
			}
			sections.push_back(a);
		}
		else if (yOrN == "image")
		{
			std::cout << "somehow you are here and its erroring out" << std::endl;
		}

		std::cout << "Do you want tabs? (y/n)" << std::endl;
		//while loop for error checking on the input from users becasue users are mean.
		while(true){
			getline(std::cin, yOrN);
			if(yOrN == "y" || yOrN == "n"){
				break;
			}
			else {
				std::cout << "there was an error in your input please enter ('y'/'n')" << std::endl;
			}
		}

		if (yOrN == "y")
		{
			//this section is error prone, i think we should look to move it to getline so that the input is forced to be a int atleast
			std::cout << "Enter the number of tabs" << std::endl;
			std::cin >> numOfTabs;
			std::cin.ignore();
			for (int i = 0; i < numOfTabs; i++) //This creates the amount of tabs(or pages) the user wants
			{
				std::cout << "Enter the link of the tab" << std::endl;
				getline(std::cin, link);
				vectOfTabs.push_back(link);
				std::cout << "Enter the name of a tab" << std::endl;
				getline(std::cin, title);
				vectOfTabs.push_back(title);
			}
			Nav nav(vectOfTabs); //This creates tabs to other pages on the website if the user wants that
			navs.push_back(nav);
			std::cout << "do you want to make another section? (y/n)" << std::endl;
			//while loop for error checking on the input from users becasue users are mean.
			while (true) {
				getline(std::cin, command);
				if (command == "y" || command == "n") {
					break;
				}
				else {
					std::cout << "there was an error in your input please enter ('y'/'n')" << std::endl;
				}
			}

		}
		else if (yOrN == "n")
		{
			std::cout << "do you want to make another section? (y/n)" << std::endl;
			//while loop for error checking on the input from users becasue users are mean.
			while(true){
				getline(std::cin,command);
				if(command == "y" || command == "n"){
					break;
				}
				else{
					std::cout << "there was an error in your input please enter ('y'/'n')" << std::endl;
				}
			}
		}
		//if this string is shown some sort of logic has failed us. you are our last hope obi-wan
		else
		{
			std::cout << "somehow you are here and its erroring out" << std::endl;
		}
	}
	print(writingIndex , userHead, navs, sections);
	//Part of Print function//ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);
	std::cout << "Hey its worked" << std::endl;
	return 0;
	}