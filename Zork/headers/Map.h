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
  public:
    string name, status, description, writing;
    //vector<Trigger> triggers;
    // Turn on
    void setName(string);
    void setStatus(string);
    void setDescription(string);
    void setWriting(string);
    friend ostream& operator<<(ostream&, const Item&);
};

ostream& operator<<(ostream& os, const Item& item)
{
  os << "Name: " << item.name << endl;
  os << "Status: " << item.status << endl;
  os << "Description: " << item.description << endl;
  os << "Writing: " << item.writing << endl;

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

// Begin Trigger Class

class Trigger
{
  public:
    //
};

// End Trigger Class

// Begin Container Class

class Container
{
  public:
    string name, status, description;
    vector<Item> acceptedItems;
    vector<Item> items;
    vector<Trigger> triggers;

    void setName(string);
    void setStatus(string);
    void setDescription(string);
    friend ostream& operator<<(ostream&, const Container&);
};

ostream& operator<<(ostream& os, const Container& newContainer)
{
  os << "Name: " << newContainer.name << endl;
  os << "Status: " << newContainer.status << endl;
  os << "Description: " << newContainer.description << endl;

  return(os);
}

void Container::setName(string a)
{
  name = a;
}

void Container::setStatus(string a)
{
  status = a;
}

void Container::setDescription(string a)
{
  description = a;
}

// End Container Class

// Begin Creature Class

class Creature
{
  public:
    void setName(string);
    void setStatus(string);
    void setDescription(string);
    friend ostream& operator<<(ostream&, const Creature&);

    string name, status, description;
    // Vulnerability, attack
    // vector<Trigger> triggers;
};

ostream& operator<<(ostream& os, const Creature& newCreature)
{
  os << "Name: " << newCreature.name << endl;
  os << "Status: " << newCreature.status << endl;
  os << "Description: " << newCreature.description << endl;

  return(os);
}

void Creature::setName(string a)
{
  name = a;
}

void Creature::setStatus(string a)
{
  status = a;
}

void Creature::setDescription(string a)
{
  description = a;
}

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
  os << "Name: " << newRoom.name << endl;
  os << "Status: " << newRoom.status << endl;
  os << "Type: " << newRoom.type << endl;
  os << "Description: " << newRoom.description << endl;

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

    vector<Room *> rooms;
    vector<Item *> items;
    vector<Creature *> creatures;
    vector<Container *> containers;

    friend ostream& operator<<(ostream&, const Map&);
    Item * itemParse(xml_node<> *);
    Room * roomParse(xml_node<> *);
    Creature * creatureParse(xml_node<> *);
    Container * containerParse(xml_node<> *);
};

ostream& operator<<(ostream& os, const Map& newMap)
{
  os << "--- Rooms ---" << endl << endl;

  for(int i = 0; i < newMap.rooms.size(); i++)
  {
    os << *newMap.rooms[i] << endl;
  }

  os << "--- Items ---" << endl;

  for(int i = 0; i < newMap.items.size(); i++)
  {
    os << *newMap.items[i] << endl;
  }

  os << "--- Creatures ---" << endl;

  for(int i = 0; i < newMap.creatures.size(); i++)
  {
    os << *newMap.creatures[i] << endl;
  }

  os << "--- Containers ---" << endl;

  for(int i = 0; i < newMap.containers.size(); i++)
  {
    os << *newMap.containers[i] << endl;
  }

  return(os);
}

Map::Map(string inputFile)
{
  file<> xmlFile(inputFile.c_str());
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

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
      rooms.push_back(newRoom);
    }
    else if(!s.compare("item"))
    {
      Item * newItem = itemParse(tag);
      items.push_back(newItem);
    }
    else if(!s.compare("container"))
    {
      Container * newContainer = containerParse(tag);
      containers.push_back(newContainer);
    }
    else if(!s.compare("creature"))
    {
      Creature * newCreature = creatureParse(tag);
      creatures.push_back(newCreature);
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
  }

  return(newRoom);
}


Container * Map::containerParse(xml_node<> * tag)
{
  Container * newContainer= new Container();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("name"))
    {
      newContainer->setName(nodeValue);
    }
    else if(!nodeName.compare("status"))
    {
      newContainer->setStatus(nodeValue);
    }
    else if(!nodeName.compare("description"))
    {
      newContainer->setDescription(nodeValue);
    }
    else if(!nodeName.compare("accept"))
    {
    }
    else if(!nodeName.compare("item"))
    {
      //Item * newItem = itemParse(temp);
    }
    else if(!nodeName.compare("trigger"))
    {
    }
  }

  return(newContainer);
}


Creature * Map::creatureParse(xml_node<> * tag)
{
  Creature * newCreature= new Creature();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("name"))
    {
      newCreature->setName(nodeValue);
    }
    else if(!nodeName.compare("status"))
    {
      newCreature->setStatus(nodeValue);
    }
    else if(!nodeName.compare("description"))
    {
      newCreature->setDescription(nodeValue);
    }
    else if(!nodeName.compare("vulnerability"))
    {
    }
    else if(!nodeName.compare("attack"))
    {
    }
    else if(!nodeName.compare("trigger"))
    {
    }
  }

  return(newCreature);
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
