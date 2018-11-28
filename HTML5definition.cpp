#include "HTML5.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


HTML::HTML()
{
	string title;
	string css;
	cout << "[Enter the title of the website]" << endl;
	cin >> title;
	cout << "[Enter the filepath of the css file]" << endl;
	cin >> css;
	cout << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>" << endl;
	head(title, css);
	body();
	cout << "</html>" << endl;
}


void HTML::head(string titleofWebsite, string Cssfilename) //This is the beginning of the code that is after the HTML declaration
{                                                                           //and the "html lang=....
	cout <<  "<head>\n" << _meta << "\n<title>" << titleofWebsite << "</title> \n" << "<link rel= \"stylesheet\" href=\"" << Cssfilename << "\"> \n" << "</head>\n";
}

void HTML::body()
{
	int f;
	int g;
	cout << "[Enter the number of tabs]" << endl;
	cin >> f;
	cout << "[Enter 0 for paragraph or 2 for image]" << endl;
	cin.ignore();
	cin >> g;
	cout << "<body>" << endl;
	header(f,g);
	section(g);
	cout << "</body>" << endl;
}

void HTML::header(int numberOfTabs, int option)
{
	cout << "<header>" << endl;
	//For starters. Do pick actual varibles later; 
	section(option);
	nav(numberOfTabs);
	cout << "</header>" << endl;
}

void HTML::section(int option)
{
	cout << "<section>" << endl;
	if (option == PARAGRAPH)
	{
		cout << "<p>" << _phrase << "</p>" << endl;
	}
	else if (option == IMAGE)   //COME BACK TO THIS LATER
	{
		cout << "Uh oh";
	}
	cout << "</section>" << endl;
}

//_phrase(phrase), 
void HTML::nav(int numOfTabs)
{
	cin.ignore();
	cout << "<nav>" << endl;
	for (int i = 0; i < numOfTabs; i++)
	{
		cout << "[Enter the name of a button]" << endl;
		getline(cin, _buttonName);
		vectOfTabs.push_back(_1stHalfButtoning + _buttonName + _2ndHalfButtoning);
	}
	string stringOfNames;
	for (auto i : vectOfTabs)
	{
		stringOfNames += i;
	}
	cout << stringOfNames;
	cout << "</nav>" << endl;
}

//string HTML::fontSize(int size, string phrase)
//{
//	return "<h" + size + '>' + phrase + "</h>";
//}