#include "HTML5.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Currently we need to write the code for a person to enter an image
//We need to make sure that the user entered an actual path to a css file and eventually an image file
//We need to ask the user for a filepath for the page of the webpage so the html can know where to open (these would be .html files)

HTML::HTML() //This is the function that starts the html writing process
{
	string title;
	string css;
	cout << "[Enter the title of the website]" << endl;
	cin >> title;
	cout << "[Enter the filepath of the css file]" << endl;
	cin >> css;
	cout << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>" << endl;
	head(title, css); //This creates the head tags and what is inside them
	body(); //This creates the body
	cout << "</html>" << endl;
}


void HTML::head(string titleofWebsite, string Cssfilename) //This is the beginning of the code that is after the HTML declaration
{                                                                           //and the "html lang=....
	cout << "<head>\n" << _meta << "\n<title>" << titleofWebsite << "</title> \n" << "<link rel= \"stylesheet\" href=\"" << Cssfilename << "\"> \n" << "</head>\n";
}

void HTML::body()
{
	cout << "<body>" << endl;
	header(); //This creates the header
	section(); //This creates the section(s)
	cout << "</body>" << endl;
}

void HTML::header()
{
	cin.ignore(); //neccessary for getline to work
	string yOrN;
	cout << "<header>" << endl;
	section();
	cout << "[Do you want tabs? (y/n)]" << endl;
	getline(cin, yOrN);
	if (yOrN == "y")
	{
		nav(); //This creates tabs to other pages on the website if the user wants that
	}
	else
	{
	}
	cout << "</header>" << endl;
}

void HTML::section()
{
	int option;
	cout << "[Enter 0 for paragraph or 2 for image]" << endl; //Either creates a paragraph or an image (currently image is not set up)
	cin >> option;
	cin.ignore();
	int numParagraphs;
	cout << "<section>" << endl;
	if (option == PARAGRAPH)
	{
		cout << "[How many paragraphs do you want]" << endl;
		cin >> numParagraphs;
		cin.ignore();
		for (int i = 0; i < numParagraphs; i++)
		{
			cout << "[What do you want to write in the paragraph]" << endl;
			getline(cin, _phrase);
			cout << "<p>" << _phrase << "</p>" << endl;
		}
	}
	else if (option == IMAGE)   //COME BACK TO THIS LATER
	{
		cout << "Not ready yet";
	}
	cout << "</section>" << endl;
}

void HTML::nav()
{
	int numOfTabs;
	cout << "[Enter the number of tabs]" << endl;
	cin >> numOfTabs;
	cin.ignore();
	cout << "<nav>" << endl;
	for (int i = 0; i < numOfTabs; i++) //This creates the amount of tabs(or pages) the user wants
	{
		cout << "[Enter the name of a tab]" << endl;
		getline(cin, _buttonName);
		vectOfTabs.push_back(_1stHalfButtoning + _buttonName + _2ndHalfButtoning);
	}
	string stringOfNames;
	for (auto i : vectOfTabs)
	{
		stringOfNames += i; //This prints them to cout
	}
	cout << stringOfNames;
	cout << "</nav>" << endl;
}

//string HTML::fontSize(int size, string phrase)
//{
//	return "<h" + size + '>' + phrase + "</h>";
//}