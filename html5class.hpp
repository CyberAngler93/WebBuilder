#ifndef HTML5CLASS_HPP_INCLUDED
#define HTML5CLASS_HPP_INCLUDED
#include <string>
#include <vector>
#include <ofstream>


class Head{
  Head(std::string , std::string);
  ~Head();
  std::string getTile();
  std::string getFile();
  void setTitle(std::string);
  std::ofstream print(std::ofstream & );
private:
  std::string _headTagOpen;
  std::string _headTitle;
  std::string _cssFile;
  std::string _meta ;
  std::string _headTagClose;
};

class Section{
public:
    std::ofstream print(std::ofstream &);
  //this is for section with only title and paragraph
  Section(std::string);
  //this is for section with title and image
  Section(std::string,std::string);
  ~Section();
private:
  std::string _sectionTagOpen;
  std::string _sectionTagClose;
  std::string _sectionTitle;
  std::string _sectionImage;
};
class Nav{
public:
    std::ofstream print (std::ofstream &);
  Nav(std::vector<std::string>);
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
