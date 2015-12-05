#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_iterators.hpp"

using namespace rapidxml;
using namespace std;

int main(int argc, char * argv[])
{
  file<> xmlFile("inputs/sample.xml");
  xml_document<> doc;
  doc.parse<0>(xmlFile.data());

  xml_node<> * node = doc.first_node();


  for(xml_node<> * pNode = node->first_node(); pNode; pNode = pNode->next_sibling())
  {
  }
  return(0);
}
