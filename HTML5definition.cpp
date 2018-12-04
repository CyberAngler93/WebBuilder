#include "HTML5.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;
#include <windows.h>
//Currently we need to write the code for a person to enter an image
//We need to make sure that the user entered an actual path to a css file and eventually an image file
//We need to ask the user for a filepath for the page of the webpage so the html can know where to open (these would be .html files)

ofstream writingIndex("index.html");

HTML::HTML() //This is the function that starts the html writing process
{
	cout << "Welcome to Web Builder!" << endl;
	string title;
	string css;
	cout << "Enter the title of the website" << endl;
	cin >> title;
	cout << "Enter the filepath of the css file" << endl;
	cin >> css;
	writingIndex << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>" << endl;
	head(title, css); //This creates the head tags and what is inside them
	body(); //This creates the body
	writingIndex << "</html>" << endl;
	ShellExecute(NULL, "open", "index.html", NULL, NULL, SW_SHOWNORMAL);
}


void HTML::head(string titleofWebsite, string Cssfilename) //This is the beginning of the code that is after the HTML declaration
{                                                                           //and the "html lang=....
	_title = titleofWebsite;
	writingIndex <<  "<head>\n" << _meta << "\n<title>" << titleofWebsite << "</title> \n" << "<link rel= \"stylesheet\" href=\"" << Cssfilename << "\"> \n" << "</head>\n";
}

void HTML::body()
{
	writingIndex << "<body>" << endl;
	header(); //This creates the header
	section(); //This creates the section(s)
	writingIndex << "</body>" << endl;
}

void HTML::header()
{
	cin.ignore(); //neccessary for getline to work
	string yOrN;
	writingIndex << "<header>" << endl;
	writingIndex << "<section style='text-align:center;height: 90px;'" << endl;
	writingIndex << "<h1>" << _title << endl;
	writingIndex << "</section>" << endl;
	section();
	cout << "Do you want tabs? (y/n)" << endl;
	getline(cin, yOrN);
	if (yOrN == "y")
	{
		nav(); //This creates tabs to other pages on the website if the user wants that
	}
	else
	{}
	writingIndex << "</header>" << endl;
}

void HTML::section()
{
	int option;
	cout << "Enter 0 for paragraph or 2 for image" << endl; //Either creates a paragraph or an image (currently image is not set up)
	cin >> option;
	cin.ignore();
	int numParagraphs;
	if (option == PARAGRAPH)
	{
		writingIndex << "<section id='Trying'>" << endl;
		cout << "How many paragraphs do you want" << endl;
		cin >> numParagraphs;
		cin.ignore();
		for (int i = 0; i < numParagraphs; i++)
		{
			cout << "What do you want to write in the paragraph" << endl;
			getline(cin, _phrase);
			writingIndex << "<p>" << _phrase << "</p>" << endl;
		}
	}
	else if(option == IMAGE)
	{
		writingIndex << "<section style='padding-bottom:50px;margin-top:40px;height:549px;width:584px;padding-top:0px;margin-left:auto;margin-right:auto;' title='Your Picture'>" << endl;
		writingIndex << "<img src='flash121a.jpg'/>" << endl;
	}
	writingIndex << "</section>" << endl;
}

void HTML::nav()
{
	int numOfTabs;
	cout << "Enter the number of tabs" << endl;
	cin >> numOfTabs;
	cin.ignore();
	writingIndex << "<nav>" << endl;
	for (int i = 0; i < numOfTabs; i++) //This creates the amount of tabs(or pages) the user wants
	{
		cout << "Enter the name of a tab" << endl;
		getline(cin, _buttonName);
		vectOfTabs.push_back(_1stHalfButtoning + _buttonName + _2ndHalfButtoning);
	}
	string stringOfNames;
	for (auto i : vectOfTabs)
	{
		stringOfNames += i; //This prints them to cout
	}
	writingIndex << stringOfNames;
	writingIndex << "</nav>" << endl;
}

//string HTML::fontSize(int size, string phrase)
//{
//	return "<h" + size + '>' + phrase + "</h>";
//}