#ifndef HTML5CLASS_HPP_INCLUDED
#define HTML5CLASS_HPP_INCLUDED
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


enum Position {LEFT, CENTER, RIGHT};

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
	//This is so I can use the setters and getters
	Section();
	//this is for section with title and image
	Section(std::string, std::string);
	Section(std::string, std::string, Position);
	~Section();
	std::string getSectionPostion();
	//This is where the style functions from css files are going to be put into section tags
	void setSectionTag(Position, std::string);
	std::string getSectionTagOpen();
	std::string getSectionTagClose();
	std::string getSectionTitle();
	void setParagraph(std::string);
	void setImage(std::string);
	void setSectionStyle(std::string);
//	void setImageId(int);
private:
	std::string _sectionTagOpenPart2;
	std::string _sectionPostion;
	std::string _sectionTagOpen;
	std::string _sectionImageTagOpen;
	std::string _sectionTagClose;
	std::string _sectionTitle;
	std::string _sectionImage;
	std::string _paragraph;
	std::string _styleTag;
	Position _position;
};
class Nav : public HTML {
public:
	void print(std::ostream &) override;
	Nav(const std::vector<std::string> &);
	//This is where the tabs will do something when you click on them
	std::string navGoToLinks(std::string);
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

#endif
