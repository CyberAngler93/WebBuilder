#ifndef HTML5_HPP_
#define HTML5_HPP_


//This file and HTML5definition is trying to make the docMaker into a html class with different funcitons
#include <string>
using std::string;
using std::getline;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;

struct HTML
{
	HTML();
	string _phrase;
	string _buttonName;
	void section(int);
	void head(string titleofWebsite, string CssFilename);
	void body();
	void header(int,int);
	void nav(int);
	//string fontSize(int, string phrase); //not sure what to call this
	string _htmlDeclaration = "<!DOCTYPE html>";
	string _htmlHeader = "<html lang=\"en\" dir=\"ltr\">";
	string _meta = "<meta charset=\"utf-8\">";
	string _1stHalfButtoning = "<a href='#'>";
	string _2ndHalfButtoning = "</a>\n";
	enum { PARAGRAPH, NAV, IMAGE };
	vector<string> vectOfTabs;
};

#endif // HTML5_HPP_