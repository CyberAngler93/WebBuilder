#include <iostream>
#include <fstream>
#include <string>
#include <ostream>


int main(){
  std::ofstream outFile("index.html");
    outFile << "<!DOCTYPE html>\n";
    outFile << "<html lang=\"en\" dir=\"ltr\">\n";
    outFile << "  <head>\n";
    outFile << "    <meta charset=\"utf-8\">\n";
    outFile << "    <title> #insertTitleHere </title>\n";
    outFile << "    <link rel= \"stylesheet\" href=\"style.css\">\n";
    outFile << "  </head>\n";
    outFile << "  <body>\n";
    outFile << "    <header>\n";
    outFile << "    <h1> Welcome To Your Webpage!\n";
    outFile << "      <nav>\n";
    outFile << "        <a href = #> #Nav1 </a>\n";
    outFile << "        <a href = #> #Nav2 </a>\n";
    outFile << "        <a href = #> #Nav3 </a>\n";
    outFile << "      </nav>\n";
    outFile << "      <section>\n";
    outFile << "        <h2> Built By Website Builder </h2>\n";
    outFile << "      </section>\n";
    outFile << "    </header>\n";
    outFile << "    <main>\n";
    outFile << "      <h3> #PutStuffHere </h3>\n";
    outFile << "    </main>\n";
    outFile << "  </body>\n";
    outFile << "</html>\n";


  return 0;
}
