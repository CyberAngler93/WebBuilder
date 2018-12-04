#include "html5class.hpp"

void HTML::print(std::vector<HTML>)
{

}
std::ostream & operator <<(std::ostream & os, const Head & head){
  os << head._headTagOpen << "\n";
  os <<  head._meta << "\n";
  os << "<title>" << head._headTitle << "</title>\n";
  os << "<link rel=\"stylesheet" << "\" href=" << head._cssFile << "\">\n";
  os << head._headTagClose << "\n";
  os << " <body>\n";
  return os;
}
Head::~Head(){

}
Section::~Section(){

}
Nav::~Nav(){

}
Head::Head(std::string userTitle, std::string userStyle){
  _headTagOpen = "  <head>";
  _headTitle = userTitle;
  _cssFile = userStyle;
  _meta = "    <meta charset=\"utf-8\">";
  _headTagClose = " </head>" ;
}
void Head::setTitle(std::string userTitle){
    _headTitle = userTitle;
}
std::string Head::getFile(){
    return this->_cssFile;
}
std::string Head::getTitle(){
    return this->_headTitle;
}
std::ostream & operator <<(std::ostream & os, const Section & section){
  os << section._sectionTagOpen << "\n";
  os << "<h1>"  << section._sectionTitle << "</h1>\n";
  os << "This needs to be fixed for images and texts!\n";
  os << section._sectionTagClose << "\n";
  return os;
}

Section::Section(std::string userTitle){
    _sectionTitle = userTitle;
    _sectionImage = "";
    _sectionTagOpen = "<section>";
    _sectionTagClose = "</section>";
}
Section::Section(std::string userTitle,std::string userImage){
    _sectionTitle = userTitle;
    _sectionImage = userImage;
    _sectionTagOpen = "<section>";
    _sectionTagClose = "</section>";
}

std::ostream & operator <<(std::ostream & os, const Nav & nav){
  os << nav._navTagOpen << "\n";
  for (int i  = 0; i < nav._navLen; i++){
  os << nav._navFormat1 << nav._linkVector[i] << nav._navFormat2 << nav._titleVector[i] << nav._navFormat3 << "\n";
  }
  os <<nav._navTagClose << "\n";
  return os;
}

Nav::Nav(const std::vector<std::string> & userNav){
    int len = 0;
    len = userNav.size();
    for(int i = 0; i < len;  i++){
        if(i%2 == 1){
            _titleVector.push_back(userNav[i]);
        }
        else{
        _linkVector.push_back(userNav[i]);
      }
    }
    _navTagClose = "</nav>";
    _navTagOpen = "<nav>";
    _navFormat1 = "<a href = \"";
    _navFormat2 =  "\"> ";
    _navFormat3 = " </a>\n";
    _navLen = len/2;
}
