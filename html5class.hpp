#ifndef HTML5CLASS_HPP_INCLUDED
#define HTML5CLASS_HPP_INCLUDED
#include <string>
#include <vector>
#include <fstream>

//I added a Header class that has getters for the open and close tags. Only because I couldn't think of a better way to include header
class HTML {
public:
	virtual void print(std::ostream &) = 0;
private:
};

class Head : public HTML {
public:
	void print(std::ostream &) override;
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

class Section : public HTML{
public:
	void print(std::ostream &) override;
	//this is for section with only title and paragraph
	Section(std::string);
	//this is for section with title and image
	Section(std::string, std::string);
	enum Position {LEFT, CENTER, RIGHT};
	Section(std::string, std::string, int);
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
	int _position;
};
class Nav : public HTML {
public:
	void print(std::ostream &) override;
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

class Header
{
public:
	Header();
	std::string getHeaderOpenTag();
	std::string getHeaderCloseTag();
private:
	std::string _headerOpenTag;
	std::string _headerCloseTag;
};
std::ostream & operator<<(std::ostream &, HTML &);

#endif
