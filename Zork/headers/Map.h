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

string convertToString(xml_node<> *, int);

// Start Item Class

class Item
{
  // Look in to "turn on" and "trigger"
  private:
    string name, status, description, writing;
  
  public:
    void setName(string);
    void setStatus(string);
    void setDescription(string);
    void setWriting(string);
    friend ostream& operator<<(ostream&, const Item&);
};

ostream& operator<<(ostream& os, const Item& item)
{
  os << "Name: " << item.name << endl << "Status: " << item.status << endl << "Description: " << item.description << endl << "Writing: " << item.writing << endl;

  return(os);
}

void Item::setName(string a)
{
  name = a;
}

void Item::setStatus(string a)
{
  status = a;
}

void Item::setDescription(string a)
{
  description = a;
}

void Item::setWriting(string a)
{
  writing = a;
}

// End Item Class

// Begin Container Class

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

// End Creature Class

// Begin Room Class

class Room 
{
  public:
    Room();
    string name, status, type, description;
    void setName(string);
    void setStatus(string);
    void setType(string);
    void setDescription(string);

    vector<char> direction;
    vector<Container> containers;
    vector<Item> items;
    vector<Creature> creatures;
    //vector<Trigger> triggers;
    friend ostream& operator<<(ostream&, const Room&);
};

Room::Room()
{
  setType("regular");
}

ostream& operator<<(ostream& os, const Room& newRoom)
{
  os << "Name: " << newRoom.name << endl << "Status: " << newRoom.status << endl << "Type: " << newRoom.type << endl << "Description: " << newRoom.description << endl;

  return(os);
}

void Room::setName(string a)
{
  name = a;
}

void Room::setStatus(string a)
{
  status = a;
}

void Room::setType(string a)
{
  type = a;
}

void Room::setDescription(string a)
{
  description = a;
}

// End Room Class

class Map
{

  public:
    Map(string);

    vector<Room> rooms;
    vector<Item> items;
    vector<Creature> creatures;
    vector<Container> containers;

    Item * itemParse(xml_node<> *);
    Room * roomParse(xml_node<> *);
};



Map::Map(string inputFile)
{
  file<> xmlFile(inputFile.c_str());
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

  //cout << (*node).name() << endl;

  // Check if (*node).name() is "map"

  for(xml_node<> * tag = node->first_node(); tag; tag = tag->next_sibling())
  {
    ostringstream ss;
    ss << (*tag).name();
    string s = ss.str();
    
    // Detrmine which type it is
    if(!s.compare("room"))
    {
      Room * newRoom = roomParse(tag);
    }
    else if(!s.compare("item"))
    {
      Item * newItem = itemParse(tag);
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


Item * Map::itemParse(xml_node<> * tag)
{
  Item * newItem = new Item();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp , 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("name"))
    {
      newItem->setName(nodeValue);
    }
    else if(!nodeName.compare("status"))
    {
      newItem->setStatus(nodeValue);
    }
    else if(!nodeName.compare("description"))
    {
      newItem->setDescription(nodeValue);
    }
    else if(!nodeName.compare("writing"))
    {
      newItem->setWriting(nodeValue);
    }
    else if(!nodeName.compare("turn on"))
    {
      // TODO
    }
    else if(!nodeName.compare("trigger")) // Double check this
    {
      // TODO
    }
  }

  //cout << *newItem;

  return(newItem);
}

Room * Map::roomParse(xml_node<> * tag)
{
  Room * newRoom = new Room();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("name"))
    {
      newRoom->setName(nodeValue);
    }
    else if(!nodeName.compare("status"))
    {
      newRoom->setStatus(nodeValue);
    }
    else if(!nodeName.compare("type"))
    {
      newRoom->setType(nodeValue);
    }
    else if(!nodeName.compare("description"))
    {
      newRoom->setDescription(nodeValue);
    }
    else if(!nodeName.compare("border"))
    {
    }
    else if(!nodeName.compare("container"))
    {
    }
    else if(!nodeName.compare("item"))
    {
    }
    else if(!nodeName.compare("creature"))
    {
    }
    else if(!nodeName.compare("trigger"))
    {
    }

    //cout << nodeName << " - " << nodeValue << endl;
  }

  cout << *newRoom;
  cout << endl;

  return(NULL);
}


// x = 0 -- name
//   = 1 -- value

string convertToString(xml_node<> * t, int x)
{
  ostringstream ss;

  if(x == 0)
  {
    ss << (*t).name();
  }
  else if(x == 1)
  {
    ss << (*t).value();
  }

  return(ss.str());
}


#endif // __MAP_H_