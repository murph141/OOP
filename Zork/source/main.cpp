#include<iostream>

#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_utils.hpp"
#include "../rapidxml/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

int main(int argc, char * argv[])
{
  file<> xmlFile("inputs/sample.xml");
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

  for(xml_node<> * tag = node->first_node(); tag; tag = tag->next_sibling())
  {
    cout << *tag << endl;
  }

  return(0);
}
