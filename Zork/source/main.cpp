#include<iostream>
#include<string>
#include<sstream>

#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_utils.hpp"
#include "../rapidxml/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

void fileParse(string);

int main(int argc, char * argv[])
{
  fileParse("inputs/sample.xml");

  return(0);
}


// Begin file parsing
void fileParse(string inputFile)
{
  // Check if file exists and you have read permission (TODO)
  
  file<> xmlFile(inputFile.c_str());
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

  for(xml_node<> * tag = node->first_node(); tag; tag = tag->next_sibling())
  {
    ostringstream ss;
    ss << (*tag).name();
    string s = ss.str();
    
    // Detrmine which type it is
    if(!s.compare("room"))
    {
      //roomParse()
    }
    else if(!s.compare("item"))
    {
      //itemParse()
    }
    else if(!s.compare("container"))
    {
      //containerParse
    }
    else if(!s.compare("creature"))
    {
      //creatureParse
    }
    else
    {
      //Error
    }
  }
}
