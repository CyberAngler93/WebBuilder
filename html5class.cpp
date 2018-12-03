#include "html5class.hpp";
std::ofstream Head::print(std::ofstream & os){
    os << _headTagOpen << "\n";
    os <<  _meta << "\n";
    os << "<title>" << _headTitle << "</title>\n";
    os << "<link rel= \"" << _cssFile << "\" href=\"style.css\">\n";
    os << _headTagClose << "\n";
    os << " <body>\n";
    return os;
}
Head::Head(std::string userTitle, std::string userStyle){
std::string _headTagOpen = "  <head>";
  std::string _headTitle = userTitle;
  std::string _cssFile = userStyle;
  std::string _meta = "    <meta charset=\"utf-8\">";
  std::string _headTagClose = " </head>" ;
}
void Head::setTitle(std::string userTitle){
    _headTitle = userTitle;
}
std::string Head::getFile(){
    return this->_cssFile;
}
std::string Head::getTitle(){
    return this->_headTitle
}

std::ofstream Section::print(std::ofstream & os){
    os << _sectionTagOpen << "\n";
    os << "<h1>"  <<_sectionTitle << "</h1>\n";
    os << "This needs to be fixed for images and texts!\n";
    os << _sectionTagClose << "\n";
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
std::ofstream Nav::print(std::ofstream & os){
    os << _navTagOpen << "\n";
    for (int i  = 0; i < _navLen; i++){
    os << _navFormat1 << _linkVector[i] << _navFormat2 << _titleVector][i] << _navFormat3 << "\n";
    }
    os << _navTagClose << "\n";
    return os;
}
Nav::Nav(std::vector<std::string> userNav){
    int len = 0;
    len = userLinks.size();
    for(int i = 0; i < len;  i++){
        if(i%2 == 1){
            _titleVector.push_back(userNav[i]);
        }
        _linkVector.push_back(userNav.[i]);
    }
    _navTagClose = "</nav>";
    _navTagOpen = "<nav>";
    _navFormat1 = "<a href = ";
    _navFormat2 =  "> ";
    _navFormat3 = " </a>\n";
    _navLen = len/2;
}
