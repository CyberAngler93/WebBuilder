#include "HTML5.hpp"

string HTML::head(ostream& os, string titleofWebsite, string Cssfilename) //This is the beginning of the code that is after the HTML declaration
{                                                                           //and the "html lang=....
	os << "<head>\n";
	os << _meta;
	os << "<title>" << titleofWebsite << "</title> \n";
	os << "<link rel= \"stylesheet\" href=\"" << Cssfilename << "\"> \n";
	os << "</head>\n";
}

string HTML::body(ostream& os)
{
	os << "<body> \n";

}

string HTML::header()
{

}

string HTML::fontSize(ostream& os, int size, string phrase)
{
	os << "<h" << size << ">" << phrase << "</h>";
}