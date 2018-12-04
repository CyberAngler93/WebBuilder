#ifndef HTML5_HPP_
#define HTML5_HPP_

/*
//This file and HTML5definition is trying to make the docMaker into a html class with different funcitons
//Currently nothing is writing to a file
#include <string>
using std::string;
using std::getline;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;

class HTML
{
	HTML();
	string _phrase;
	string _buttonName;
	string _title;
	void section();
	void head(string titleofWebsite, string CssFilename);
	void body();
	void header();
	void nav();
	//string fontSize(int, string phrase); //not sure what to call this
	string _htmlDeclaration = "<!DOCTYPE html>";
	string _htmlHeader = "<html lang=\"en\" dir=\"ltr\">";
	string _meta = "<meta charset=\"utf-8\">";
	string _1stHalfButtoning = "<a href='#Trying'>";
	string _2ndHalfButtoning = "</a>\n";
	enum { PARAGRAPH, IMAGE };
	vector<string> vectOfTabs;
};

#endif // HTML5_HPP_

*/
//#ifndef HTML5CLASS_HPP_INCLUDED
//#define HTML5CLASS_HPP_INCLUDED
#include <string>
#include <vector>
#include <fstream>



class HTML {
public:

	void print();
private:
};



class Head{
public:
	void print(std::ostream &);
	Head(std::string, std::string);
	~Head();
	std::string getTitle();
	std::string getFile();
	void setTitle(std::string);
private:
	std::string _headTagOpen;
	std::string _headTitle;
	std::string _cssFile;
	std::string _meta;
	std::string _headTagClose;
};

class Section{
public:
	void print(std::ostream &);
	//this is for section with only title and paragraph
	Section(std::string);
	//this is for section with title and image
	Section(std::string, std::string);
	Section(std::string, std::string, int);
	~Section();
private:
	std::string _sectionPostion;
	std::string _sectionTagOpen;
	std::string _sectionTagClose;
	std::string _sectionTitle;
	std::string _sectionImage;
};
class Nav{
public:
	void print(std::ostream &);
	Nav(const std::vector<std::string> &);
	~Nav();
private:
	std::vector<std::string> _titleVector;
	std::vector<std::string> _linkVector;
	std::string _navTagOpen;
	std::string _navTagClose;
	std::string _navFormat1;
	std::string _navFormat2;
	std::string _navFormat3;
	int _navLen = 0;
};

std::ostream & operator<<(std::ostream &, HTML &);

#endif
