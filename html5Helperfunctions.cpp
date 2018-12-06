//Helper functions definitions

#include "html5Helperfunctions.hpp"

//The last function is me trying to make the title of section be the title of _sectionTagParameter
//std::vector<std::string> tabTitles;
std::string _sectionTagParameter;

//this is handleinput checking for numbers! if oyu want a number from the user lets use this!
void handleInputWithChecking(std::istream & is,std::stringstream & ss, std::string question, int & userAnswer){
		std::string input = "";
		std::cout << 	question << std::endl;
		while(true){
			getline(is,input);
			ss.str(input);
			if(ss >> userAnswer){
				if(userAnswer > 0 && userAnswer <= 10){
					break;
				}
			}
				std::cout << "Not a valid number please enter between 1 and 10" << std::endl;
			}
		}
//this is the error checking function that takes an inputstream, question, string you need answer in, and type of question. feel free to add more types to questions
void handleInputWithChecking(std::istream & is, std::string question, std::string & userAnswer,int typeOfQuestion){
	std::cout << 	question << std::endl;
		while(true){
			getline(is,userAnswer);
			if(typeOfQuestion == 1){
				if(userAnswer == "y" || userAnswer == "n"){
					break;
				}else{
					std::cout << "There was an error in your input please enter  ('y'/'n')" << std::endl;
				}
			}else if (typeOfQuestion == 2){
				if(userAnswer == "paragraph" || userAnswer == "image" || userAnswer == "n"){
					break;
				}else{
					std::cout << "There was an error in nyour input please enter 'paragraph'/'image'/'n'" << std::endl;
				}
			}else if (typeOfQuestion == 3){
				if(!userAnswer.empty()){
						break;
				}
				else{
					std::cout << "there was an error in your input it must not be empty!" << std::endl;
				}
			}else if (typeOfQuestion == 4){
				if(userAnswer == "left" || userAnswer == "right" || userAnswer == "center"){
					break;
				}else{
					std::cout << "there was an error in your input needs to be 'left'/'right'/'center'" << std::endl;
				}
			}else if(typeOfQuestion == 5){
				if(userAnswer == "exit" || userAnswer == "help" || userAnswer == "nav" || userAnswer == "section"){
					break;
				}else{
					std::cout << "invalid command passed please try again or type help!" << std::endl;
				}
			}
		}
}


void makeSections(std::istream & is, std::vector<Section> & sections){
		std::string userInput;
		std::string title;
		Position enumPosition = LEFT;
		handleInputWithChecking(is,"Do you want a paragraph or image in this section?",userInput,2);
		while(true){
			if (userInput == "paragraph")
			{
				handleInputWithChecking(is,"Enter the title of the Section",title,3);
				//tabTitles.push_back(title);
				Section userSection(title);
				std::cout << "Enter exit when you are done entering your paragraph" << std::endl;
				while (getline(is, userInput))
				{
					if (userInput == "exit")
					{
							break;
					}
					else
					{
						userSection.setParagraph(userInput + " ");
					}
				}
				//insert style function here to get tags?


			userSection.setSectionStyle(userInput);
			sections.push_back(userSection);
			break;
			}
			else if (userInput == "image")
			{
				handleInputWithChecking(is,"Enter the title of the Picture",title,3);
				//numOfPics++
				handleInputWithChecking(is,"Do you want it on the left, center, or right",userInput,3);
				if(userInput == "left"){
					enumPosition = LEFT;
				}else if(userInput == "right"){
					enumPosition = RIGHT;
				}else{
					enumPosition = CENTER;
				}
				handleInputWithChecking(is,"Enter the file for the picture, be sure to include it in the folder for the html",userInput,3);
				Section userSection(title, userInput, enumPosition);
				//b.setImageId(numOfPics);
				std::cout << "This is enumPosition: " << enumPosition << std::endl;
				//insert style set function here some function to create the tags to push into the memeber variables!

				userSection.setSectionStyle(userInput);
				sections.push_back(userSection);
				break;
				std::cout << "can't do this yet" << std::endl;
			}
			else{
				std::cout << "this is broken land, you shouldnt be here." << std::endl;
			}
		}

}

//Make nav fucntion when you want to make a nav call this in main!
void makeNav(std::istream & is,std::stringstream & ss,std::vector<Nav> & navs){
	std::vector<std::string> vectOfTabs;
	std::string input;
	int numOfTabs = 0;
	//this section is error prone, i think we should look to move it to getline so that the input is forced to be a int atleast
	handleInputWithChecking(is,ss,"Enter the number of tabs",numOfTabs);
	for (int i = 0; i < numOfTabs; i++) //This creates the amount of tabs(or pages) the user wants
	{
		//link input
		handleInputWithChecking(is,"Enter the link of the tab",input,3);
		vectOfTabs.push_back(input);
		//title input
		handleInputWithChecking(is,"Enter the title of the tab",input,3);
		vectOfTabs.push_back(input);
	}
	Nav nav(vectOfTabs); //This creates tabs to other pages on the website if the user wants that
	navs.push_back(nav);
}

//this is the print function defined for outputing our objects to an ofstream
//needs some tweaking to get rocking and rolling

void print(std::ostream & os,Head & head,std::vector<Nav> & nav, std::vector<Section> & sec){
	int navLen = nav.size();
	int secLen = sec.size();
	os << "<!DOCTYPE html>\n<html lang = 'en' dir = 'ltr'>\n";

	head.print(os);
	//why this random head tags??
	//os << "<header>" << std::endl;
	for(int i = 0; i < navLen; i++){
		nav[i].print(os);
	}
	//why random head tags???
//	os << "</header>" << std::endl;
	for(int i = 0; i < secLen; i++){
		sec[i].print(os);
	}
	os << "</body> \n </html>" << std::endl;

}
/*
void placeImage()
{

}

void setSectionTagParameter(std::string a)
{
	_sectionTagParameter = a;
	std::cout << "This is the parameter: [" << _sectionTagParameter << "]" << std::endl;
	std::cout << "This is title: [" << a << "]" << std::endl;
}*/
