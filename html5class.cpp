#include "html5class.hpp"

std::ostream & operator<<(std::ostream & os, HTML & html){
  html.print(os);
  return os;
}

void Head::print(std::ostream & os){
  os << _headTagOpen << "\n";
  os << _meta << "\n";
  os << "<title>" << _headTitle << "</title>\n";
  os << "<link rel=\"stylesheet" << "\" href= \"" << _cssFile << "\">\n";
  os << _headTagClose << "\n";
  os << " <body>\n";
}




Head::Head(std::string userTitle, std::string userStyle): _headTagOpen("  <head>"), _headTitle(userTitle), _cssFile(userStyle), _meta("    <meta charset=\"utf-8\">"), _headTagClose(" </head>")
{}

Head::~Head() {

}


void Head::setTitle(std::string userTitle){
    _headTitle = userTitle;
}

std::string Head::getFile(){
    return _cssFile;
}

std::string Head::getTitle(){
    return _headTitle;
}

std::string Head::getHeadTagOpen()
{
	return _headTagOpen;
}

std::string Head::getHeadTitle()
{
	return _headTitle;
}

std::string Head::getCssFile()
{
	return _cssFile;
}

std::string Head::getMeta()
{
	return _meta;
}

std::string Head::getHeadTagClose()
{
	return _headTagClose;
}





Section::Section(std::string userTitle) : _sectionTitle(userTitle), _sectionImage(""), _sectionTagOpen("<section>"), _sectionTagClose("</section>")
{}

Section::Section(std::string userTitle, std::string userImage) : _sectionTitle(userTitle), _sectionImage(userImage), _sectionTagOpen("<section>"), _sectionTagClose("</section>")
{}

Section::Section(std::string userTitle, std::string userImage, Position position) : _sectionTitle(userTitle), _sectionImage(userImage), _sectionTagClose("</section>"), _position(position)
{
	setSectionTag(position, userTitle);
}

std::string Section::getSectionPostion()
{
	return _sectionPostion;
}

std::string Section::getSectionTagOpen()
{
	return _sectionTagOpen;
}

std::string Section::getSectionTagClose()
{
	return _sectionTagClose;
}

std::string Section::getSectionTitle()
{
	return _sectionTitle;
}


void Section::print(std::ostream & os)
{
  os << "we are making to this stage in the system" << std::endl;
	if (!_sectionImage.empty())
	{
		os << _sectionImageTagOpen << "\n";
		os << "<h1>" << _sectionTitle << "</h1>\n";
		os << "<img src=\"" << _sectionImage <<"\"/>\n";
		//os << "This needs to be fixed for images!\n";
	}
	else if (!_paragraph.empty())
	{
		os << _sectionTagOpen << "\n";
		os << "<h1>" << _sectionTitle << "</h1>\n";
		os << "<p>" <<_paragraph << "</p>\n";
	} 
	//os << "This needs to be fixed for images and texts!\n";
	os << _sectionTagClose << "\n";
}

void Section::setParagraph(std::string phrases)
{
	_paragraph += phrases;
}

void Section::setSectionStyle(std::string tags){
  _styleTag += tags;
}
/*
void Section::setImageSectPostion(int position)
{
	_position = position;
}
*/
void Section::setImage(std::string file)
{
	_sectionImage = file;
}

/*void Section::setImageId(int ID)
{
	_id = ID;
}
*/

Section::Section() {

}
Section::~Section() {

}

std::string id = "\"t\"";

void Section::setSectionTag(Position positions, std::string title)
{
	std::cout << "If you are seeing this then you are in setSectionTag and positions is: " << positions << std::endl;
	if (positions == 0)
	{
		_sectionImageTagOpen = "<section title=\"" + title + "\" id = \"" + _sectionTagParameter + "\""">";
	}
	else if (positions == 1)
	{
		_sectionImageTagOpen = "<section class=\"center\" title=\"" + title + "\" id = \"" + _sectionTagParameter + "\""">";
	}
	else if (positions == 2)
	{
		_sectionImageTagOpen = "<section class=\"right\" title=\"" + title + "\" id = \"" + _sectionTagParameter + "\""">";
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Nav::print(std::ostream & os){
  os << _navTagOpen << "\n";
  for (int i  = 0; i < _navLen; i++){
	  Section b(_linkVector[i]);
	  b.setSectionTagParameter(b);
  os << _navFormat1 << _linkVector[i] << _navFormat2 << _titleVector[i] << _navFormat3;
  }
  os << _navTagClose;
}

Nav::Nav(const std::vector<std::string> & userNav): _navTagClose("</nav>"), _navTagOpen("<nav>"), _navFormat1("<a href = \"#"), _navFormat2("\">"), _navFormat3(" </a>\n")
{
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
    _navLen = len/2;
}

std::string Nav::navGoToLinks(std::string linking)
{
	//std::cout << _navFormat1;
	return _navFormat1;
}

Nav::~Nav() {

}
