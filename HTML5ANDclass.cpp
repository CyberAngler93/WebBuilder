#include "html5class.hpp"
#include <iostream>
int main()
{
	std::ofstream writingIndex("index.html");

	std::cout << "Welcome to Web Builder!" << std::endl;
	std::string title;
	std::string css;
	std::cout << "Enter the title of the website" << std::endl;
	std::cin >> title;
	std::cout << "Enter the filepath of the css file" << std::endl;
	std::cin >> css;
	Head a(title, css);
	std::cin.ignore();
	Section b(title);
	std::vector<Nav> navs;
	std::vector<Section> sections;
	std::string command = "y";
	while (command == "y")
	{
		std::cout << "What is the title of the section?" << std::endl;
		getline(std::cin, title);
		Section c(title);
		sections.push_back(c);
		std::string yOrN;
		std::cout << "Do you want tabs? (y/n)" << std::endl;
		getline(std::cin, yOrN);
		if (yOrN == "y")
		{
			int numOfTabs;
			std::string _buttonName;
			std::string _buttonLink;
			std::cout << "Enter the number of tabs" << std::endl;
			std::cin >> numOfTabs;
			std::vector<std::string> vectOfTabs;
			std::cin.ignore();
			for (int i = 0; i < numOfTabs * 2; i++) //This creates the amount of tabs(or pages) the user wants
			{
				std::cout << "Enter the link of the tab" << std::endl;
				getline(std::cin, _buttonLink);
				vectOfTabs.push_back(_buttonLink);
				std::cout << "Enter the name of a tab" << std::endl;
				getline(std::cin, _buttonName);
				vectOfTabs.push_back(_buttonName);
			}
			Nav nav(vectOfTabs); //This creates tabs to other pages on the website if the user wants that
			navs.push_back(nav);
		}
		else
		{

		}

		std::cout << "do you want to make another section? (y/n)" << std::endl;
		getline(std::cin, command);
	}


	
	//Part of Print function//ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);
	return 0;
}

//This is to be worked on later
/*
void print(std::ostream os, Head a, Section b, Nav c)
{
	os << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>\n";
	os << a.getHeadTagOpen() << "\n";
	os << a.getMeta() << "\n";
	os << "<title>" << a.getHeadTitle() << "</title>\n";
	os << "<link rel=\"stylesheet" << "\" href=" << a.getCssFile() << "\">\n";
	os << a.getHeadTagClose() << "\n";
	os << " <body>\n";
	os << "<header>\n";
	os << b.getSectionTagOpen() << std::endl;
	os << "<h1>" << b.getSectionTitle() << "</h1>\n";
	os << b.getSectionTagClose() << std::endl;
	os << c.getNavTagOpen() << std::endl;
	for (int i = 0; i < c.getTitleVector.size(); i++)
	{
		std::cout << "<a href='#Trying'>" << c.getNavFormat1() << c.getLinkVector[i] << c.getNavFormat2 << c.getTitleVector[i] << "</a>" << c.getNavFormat3() << std::endl;
	}
	////
	////
	////
	os << "</header>" << std::endl;
}*/