#ifndef __MAP_H_
#define __MAP_H_

#include<vector>
#include<iostream>
#include<string>
#include<sstream>

#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_utils.hpp"
#include "../rapidxml/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

class Item
{
};


class Container
{
  private:
    string name, status, description;
    //vector<Accept> acceptedItems;
    vector<Item> items;
    //vector<Trigger> triggers;

  public:
};


class Creature
{
};

class Room 
{
  private:
    // Add stuff
    string name, status, type, description;
    vector<char> direction;
    vector<Container> containers;
    vector<Item> items;
    vector<Creature> creatures;
    //vector<Trigger> triggers;
    

  public:
    // Add stuff
};


class Map
{
  private:
    vector<Room> rooms;

  public:
    Map();
    Map(string);
    void itemParse(xml_node<> *);

    void addRoom();
};



Map::Map(string inputFile)
{
  file<> xmlFile(inputFile.c_str());
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

  cout << (*node).name() << endl;

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
      itemParse(tag);
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


void Map::itemParse(xml_node<> * tag)
{
  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    cout << (*temp).name() << " - " << (*temp).value() << endl;
  }

  cout << endl;
}

#endif // __MAP_H_
