//This file and HTML5definition is trying to make the docMaker into a html class with different funcitons
#include <string>
using std::string;
#include <ostream>
using std::ostream;
struct HTML
{
	HTML();
	string section();
	string head(string titleofWebsite, string CssFilename);
	string body();
	string header();
	string fontSize(int, string phrase); //not sure what to call this
	string _htmlDeclaration = "<!DOCTYPE html>";
	string _htmlHeader = "<html lang=\"en\" dir=\"ltr\">";
	string _meta = "<meta charset=\"utf-8\">";
};