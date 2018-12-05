#ifndef HTML5CLASS_HPP_INCLUDED
#define HTML5CLASS_HPP_INCLUDED
#include <string>
#include <vector>
#include <fstream>


//This is supposed to be here
class HTML {
public:
	void print(std::ostream &);
private:
};

class Head {
public:
	void print(std::ostream &);
	Head(std::string, std::string);
	~Head();
	std::string getTitle();
	std::string getFile();
	void setTitle(std::string);
	std::string getHeadTagOpen();
	std::string getHeadTitle();
	std::string getCssFile();
	std::string getMeta();
	std::string getHeadTagClose();
private:
	std::string _headTagOpen;
	std::string _headTitle;
	std::string _cssFile;
	std::string _meta;
	std::string _headTagClose;
};

class Section {
public:
	void print(std::ostream &);
	//this is for section with only title and paragraph
	Section(std::string);
	//this is for section with title and image
	Section(std::string, std::string);
	//Section(std::string, std::string, int); This is commented out because I didn't feel like defining it
	~Section();
	std::string getSectionPostion();
	std::string getSectionTagOpen();
	std::string getSectionTagClose();
	std::string getSectionTitle();
	std::string getSectionImage();
private:
	std::string _sectionPostion;
	std::string _sectionTagOpen;
	std::string _sectionTagClose;
	std::string _sectionTitle;
	std::string _sectionImage;
};
class Nav {
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
