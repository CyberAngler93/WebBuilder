//This file and HTML5definition is trying to make the docMaker into a html class with different funcitons
#include <string>
using std::string;
#include <ostream>
using std::ostream;
class HTML
{
public:
	string head(ostream&, string titleofWebsite, string CssFilename);
	string body(ostream&);
	string header();
	string fontSize(ostream&, int, string phrase); //not sure what to call this
private:
	string _htmlDeclaration = "<!DOCTYPE html>";
	string _htmlHeader = "<html lang=\"en\" dir=\"ltr\">";
	string _meta = "<meta charset=\"utf-8\">";
};