


class Head{
  Head(std::string , std::string);
  ~Head();
  std::string getTile();
  std::string getFile();
  void setTitle(std::string);
private:
  std::string _headTagOpen = "<head>";
  std::string _headTitle;
  std::string _cssFile;
  std::string _meta = "<meta charset=\"utf-8\">";
  std::string _headTagClose = "</head>";
};

class Section{
public:
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


private:




};


class Foot{





};







class Header(){
public:
  Header();
  ~Header();
  print();

private:
  string _title;
};
class Nav(){
public:
  Nav();
  ~Nav();
  print();
private:
  int _numberOfNav;
  std::vector<std::string> _titleVector;
};
class Section(){
public:
  Section();
  ~Section();
  print();
private:
  string _title;



};
