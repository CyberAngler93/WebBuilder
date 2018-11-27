#include "HTML5.hpp"

HTML::HTML()
{
	string title;
	string css;
	head(title, css);
	body();
}

string HTML::head(string titleofWebsite, string Cssfilename) //This is the beginning of the code that is after the HTML declaration
{                                                                           //and the "html lang=....
	return  "<head>\n" + _meta + "<title>" + titleofWebsite + "</title> \n" + "<link rel= \"stylesheet\" href=\"" + Cssfilename + "\"> \n" + "</head>\n";
}

string HTML::body()
{
	//Header()
	//Section()+
}

string HTML::header()
{
	//Section()

}

string HTML::section()
{
	//bulk of website:
	//1)paragraphs
	//2)nav
	//3)images
}

string HTML::fontSize(int size, string phrase)
{
	return "<h" + size + '>' + phrase + "</h>";
}