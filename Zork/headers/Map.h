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

// Begin Condition Class

class Condition
{
  public:
    void setObject(string);
    void setStatus(string);
    void setHas(string);
    void setOwner(string);
    friend ostream& operator<<(ostream&, const Condition&);
    string object, status, has, owner;

};

ostream& operator<<(ostream& os, const Condition& newCondition)
{
  os << "Object: " << newCondition.object << endl;
  os << "Status: " << newCondition.status << endl;
  os << "Has: " << newCondition.has << endl;
  os << "Owner: " << newCondition.owner << endl;

  return(os);
}

void Condition::setObject(string a)
{
  object = a;
}

void Condition::setStatus(string a)
{
  status = a;
}

void Condition::setHas(string a)
{
  has = a;
}

void Condition::setOwner(string a)
{
  owner = a;
}

// End Condition Class

// Begin Trigger Class

class Trigger
{
  public:
    void setType(string);
    void setCommand(string);
    void setPrint(string);
    void setAction(string);
    friend ostream& operator<<(ostream&, const Trigger&);

    string type, command, print;
    Condition * condition;
    vector<string> actions;
};

ostream& operator<<(ostream& os, const Trigger& newTrigger)
{
  os << "Type: " << newTrigger.type << endl;
  os << "Command: " << newTrigger.command << endl;
  os << "Print: " << newTrigger.print << endl;
  os << "Actions: " << endl;

  for(int i = 0; i < newTrigger.actions.size(); i++)
  {
    os << newTrigger.actions[i] << endl;
  }

  os << "Condition: " << endl << *newTrigger.condition;

  return(os);
}

void Trigger::setType(string a)
{
  type = a;
}

void Trigger::setCommand(string a)
{
  command = a;
}

void Trigger::setPrint(string a)
{
  print = a;
}

void Trigger::setAction(string a)
{
  actions.push_back(a);
}

// End Trigger Class

// Begin Turnon Class

class Turnon
{
  public:
    void setPrint(string);
    void setAction(string);
    friend ostream& operator<<(ostream&, const Turnon&);

    string print, action;
    int on;
};

ostream& operator<<(ostream& os, const Turnon& newTurnon)
{
  os << "Print: " << newTurnon.print << endl;
  os << "Action: " << newTurnon.action << endl;

  return(os);
}

void Turnon::setPrint(string a)
{
  print = a;
}

void Turnon::setAction(string a)
{
  action = a;
}

// End Turnon Class

// Begin Border Class

class Border
{
  public:
    void setDirection(string);
    void setName(string);
    friend ostream& operator<<(ostream&, const Border&);

    string name, direction;
};

ostream& operator<<(ostream& os, const Border& newBorder)
{
  os << "Direction: " << newBorder.direction << endl;
  os << "Name: " << newBorder.name << endl;
}

void Border::setDirection(string a)
{
  direction = a;
}

void Border::setName(string a)
{
  name = a;
}

// End Border Class

// Begin Item Class

class Item
{
  public:
    string name, status, description, writing;
    vector<Trigger *> triggers;
    Turnon * turnon;
    void setName(string);
    void setStatus(string);
    void setDescription(string);
    void setWriting(string);
    friend ostream& operator<<(ostream&, const Item&);
};

ostream& operator<<(ostream& os, const Item& newItem)
{
  os << "Name: " << newItem.name << endl;
  os << "Status: " << newItem.status << endl;
  os << "Description: " << newItem.description << endl;
  os << "Writing: " << newItem.writing << endl;

  os << "Triggers: " << endl;

  for(int i = 0; i < newItem.triggers.size(); i++)
  {
    os << newItem.triggers[i] << endl;
  }

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
  public:
    int open;
    string name, status, description;
    vector<string> acceptedItems;
    vector<string> items;
    vector<Trigger *> triggers;

    void setName(string);
    void setStatus(string);
    void setDescription(string);
    void setAccept(string);
    void setItem(string);
    friend ostream& operator<<(ostream&, const Container&);
};

ostream& operator<<(ostream& os, const Container& newContainer)
{
  os << "Open: " << newContainer.open << endl;
  os << "Name: " << newContainer.name << endl;
  os << "Status: " << newContainer.status << endl;
  os << "Description: " << newContainer.description << endl;
  os << "Accepts: " << endl;

  for(int i = 0; i < newContainer.acceptedItems.size(); i++)
  {
    os << newContainer.acceptedItems[i] << endl;
  }

  os << "Items: " << endl;

  for(int i = 0; i < newContainer.items.size(); i++)
  {
    os << newContainer.items[i] << endl;
  }

  os << "Triggers: " << endl;

  for(int i = 0; i < newContainer.triggers.size(); i++)
  {
    os << *newContainer.triggers[i] << endl;
  }

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

void Container::setAccept(string a)
{
  acceptedItems.push_back(a);
}

void Container::setItem(string a)
{
  items.push_back(a);
}

// End Container Class

// Begin Attack Class

class Attack
{
  public:
    void setActions(string);
    void setPrint(string);
    friend ostream& operator<<(ostream&, const Attack&);

    Condition * condition;
    vector<string> actions;
    string print;
};

ostream& operator<<(ostream& os, const Attack& newAttack)
{
  os << "Print: " << newAttack.print << endl;

  os << endl << "Actions: " << endl;

  for(int i = 0; i < newAttack.actions.size(); i++)
  {
    os << newAttack.actions[i] << endl;
  }

  os << endl << "Condition: " << endl;

  os << *newAttack.condition;

  return(os);
}

void Attack::setActions(string a)
{
  actions.push_back(a);
}

void Attack::setPrint(string a)
{
  print = a;
}

// End Attack Class

// Begin Creature Class

class Creature
{
  public:
    void setName(string);
    void setStatus(string);
    void setDescription(string);
    void setVulnerability(string);
    friend ostream& operator<<(ostream&, const Creature&);

    string name, status, description;
    vector<string> vulnerabilities;
    vector<Trigger *> triggers;
    Attack * attack;
};

ostream& operator<<(ostream& os, const Creature& newCreature)
{
  os << "Name: " << newCreature.name << endl;
  os << "Status: " << newCreature.status << endl;
  os << "Description: " << newCreature.description << endl;
  os << "Vulnerabilities: " << endl;

  for(int i = 0; i < newCreature.vulnerabilities.size(); i++)
  {
    os << newCreature.vulnerabilities[i] << endl;
  }

  os << "Triggers: " << endl;

  for(int i = 0; i < newCreature.triggers.size(); i++)
  {
    os << *newCreature.triggers[i] << endl;
  }

  os << "Attack: " << *newCreature.attack;

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

void Creature::setVulnerability(string a)
{
  vulnerabilities.push_back(a);
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
    void setItem(string);
    void setCreature(string);
    void setContainer(string);

    vector<Border *> borders;
    vector<string> containers;
    vector<string> items;
    vector<string> creatures;
    vector<Trigger *> triggers;
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

  os << "Containers: " << endl;

  for(int i = 0; i < newRoom.containers.size(); i++)
  {
    os << newRoom.containers[i] << endl;
  }

  os << "Items: " << endl;

  for(int i = 0; i < newRoom.items.size(); i++)
  {
    os << newRoom.items[i] << endl;
  }

  os << "Creatures: " << endl;

  for(int i = 0; i < newRoom.creatures.size(); i++)
  {
    os << newRoom.creatures[i] << endl;
  }

  os << "Triggers: " << endl;

  for(int i = 0; i < newRoom.triggers.size(); i++)
  {
    os << *newRoom.triggers[i] << endl;
  }

  os << "Borders: " << endl;

  for(int i = 0; i < newRoom.borders.size(); i++)
  {
    os << *newRoom.borders[i] << endl;
  }

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

void Room::setItem(string a)
{
  items.push_back(a);
}

void Room::setCreature(string a)
{
  creatures.push_back(a);
}

void Room::setContainer(string a)
{
  containers.push_back(a);
}

// End Room Class

class Map
{

  public:
    Map(string);
    virtual ~Map();

    Room * currentRoom;
    vector<Room *> rooms;
    vector<Item *> items;
    vector<Creature *> creatures;
    vector<Container *> containers;
    vector<string> inventory;
    int gameOver;

    friend ostream& operator<<(ostream&, const Map&);
    Item * itemParse(xml_node<> *);
    Room * roomParse(xml_node<> *);
    Creature * creatureParse(xml_node<> *);
    Container * containerParse(xml_node<> *);
    Attack * attackParse(xml_node<> *);
    Condition * conditionParse(xml_node<> *);
    Trigger * triggerParse(xml_node<> *);
    Border * borderParse(xml_node<> *);
    Turnon * turnonParse(xml_node<> *);

    void startGame();
    void moveRooms(string);
    void printInventory();
    void takeItem(string);
    void openExit();
    void openContainer(string);
    void readItem(string);
    void dropItem(string);
    void putItemInContainer(string, string);
    void turnOnItem(string);
    void attackCreature(string, string);

};

Map::~Map()
{
  // TODO
}

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

  os << endl;

  return(os);
}

Map::Map(string inputFile)
{
  gameOver = 0;

  file<> xmlFile(inputFile.c_str());
  xml_document<> doc;
  xml_node<> * node;

  doc.parse<0>(xmlFile.data());

  node = doc.first_node();

  // Check for correct XML formatting
  if(convertToString(node, 0).compare("map"))
  {
    cout << "Error, XML formatting is incorrect" << endl;
  }

  for(xml_node<> * tag = node->first_node(); tag; tag = tag->next_sibling())
  {
    string nodeName = convertToString(tag, 0);

    if(!nodeName.compare("room"))
    {
      Room * newRoom = roomParse(tag);
      rooms.push_back(newRoom);
    }
    else if(!nodeName.compare("item"))
    {
      Item * newItem = itemParse(tag);
      items.push_back(newItem);
    }
    else if(!nodeName.compare("container"))
    {
      Container * newContainer = containerParse(tag);
      containers.push_back(newContainer);
    }
    else if(!nodeName.compare("creature"))
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
    else if(!nodeName.compare("turnon"))
    {
      Turnon * newTurnon = turnonParse(temp);
      newItem->turnon = newTurnon;
    }
    else if(!nodeName.compare("trigger"))
    {
      Trigger * newTrigger = triggerParse(temp);
      newItem->triggers.push_back(newTrigger);
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
      Border * newBorder = borderParse(temp);
      newRoom->borders.push_back(newBorder);
    }
    else if(!nodeName.compare("container"))
    {
      newRoom->setContainer(nodeValue);
    }
    else if(!nodeName.compare("item"))
    {
      newRoom->setItem(nodeValue);
    }
    else if(!nodeName.compare("creature"))
    {
      newRoom->setCreature(nodeValue);
    }
    else if(!nodeName.compare("trigger"))
    {
      Trigger * newTrigger = triggerParse(temp);
      newRoom->triggers.push_back(newTrigger);
    }
  }

  return(newRoom);
}


Container * Map::containerParse(xml_node<> * tag)
{
  Container * newContainer = new Container();

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
      newContainer->setAccept(nodeValue);
    }
    else if(!nodeName.compare("item"))
    {
      newContainer->setItem(nodeValue);
    }
    else if(!nodeName.compare("trigger"))
    {
      Trigger * newTrigger = triggerParse(temp);
      newContainer->triggers.push_back(newTrigger);
    }
  }

  return(newContainer);
}


Creature * Map::creatureParse(xml_node<> * tag)
{
  Creature * newCreature = new Creature();

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
      newCreature->setVulnerability(nodeValue);
    }
    else if(!nodeName.compare("attack"))
    {
      newCreature->attack = attackParse(temp);
    }
    else if(!nodeName.compare("trigger"))
    {
      Trigger * newTrigger = triggerParse(temp);
      newCreature->triggers.push_back(newTrigger);
    }
  }

  return(newCreature);
}

Attack * Map::attackParse(xml_node<> * tag)
{
  Attack * newAttack = new Attack();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("print"))
    {
      newAttack->setPrint(nodeValue);
    }
    else if(!nodeName.compare("action"))
    {
      newAttack->setActions(nodeValue);
    }
    else if(!nodeName.compare("condition"))
    {
      newAttack->condition = conditionParse(temp);
    }
  }

  return(newAttack);
}

Condition * Map::conditionParse(xml_node<> * tag)
{
  Condition * newCondition = new Condition();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("object"))
    {
      newCondition->setObject(nodeValue);
    }
    else if(!nodeName.compare("status"))
    {
      newCondition->setStatus(nodeValue);
    }
    else if(!nodeName.compare("has"))
    {
      newCondition->setHas(nodeValue);
    }
    else if(!nodeName.compare("owner"))
    {
      newCondition->setOwner(nodeValue);
    }
  }

  return(newCondition);
}

Trigger * Map::triggerParse(xml_node<> * tag)
{
  Trigger * newTrigger = new Trigger();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("type"))
    {
      newTrigger->setType(nodeValue);
    }
    else if(!nodeName.compare("command"))
    {
      newTrigger->setCommand(nodeValue);
    }
    else if(!nodeName.compare("condition"))
    {
      Condition * newCondition = conditionParse(temp);
      newTrigger->condition = newCondition;
    }
    else if(!nodeName.compare("action"))
    {
      newTrigger->setAction(nodeValue);
    }
    else if(!nodeName.compare("print"))
    {
      newTrigger->setPrint(nodeValue);
    }
  }

  return(newTrigger);
}

Border * Map::borderParse(xml_node<> * tag)
{
  Border * newBorder = new Border();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("direction"))
    {
      nodeValue = nodeValue[0];
      newBorder->setDirection(nodeValue);
    }
    else if(!nodeName.compare("name"))
    {
      newBorder->setName(nodeValue);
    }
  }

  return(newBorder);
}

Turnon * Map::turnonParse(xml_node<> * tag)
{
  Turnon * newTurnon = new Turnon();

  for(xml_node<> * temp = tag->first_node(); temp; temp = temp->next_sibling())
  {
    string nodeName = convertToString(temp, 0);
    string nodeValue = convertToString(temp, 1);

    if(!nodeName.compare("print"))
    {
      newTurnon->setPrint(nodeValue);
    }
    else if(!nodeName.compare("action"))
    {
      newTurnon->setAction(nodeValue);
    }
  }

  return(newTurnon);
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

// End Parsing Logic

void Map::startGame()
{
  currentRoom = NULL;

  for(int i = 0; i < rooms.size(); i++)
  {
    if(!rooms[i]->name.compare("Entrance"))
    {
      currentRoom = rooms[i];
      break;
    }
  }

  if(!currentRoom) cout << "ERROR" << endl;

  cout << currentRoom->description << endl;

  string input;

  do
  {
    cout << "> ";
    getline(cin, input);

    istringstream iss(input);
    vector<string> vec;

    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(vec));

    if(vec.size() == 1 && (!input.compare("n") || !input.compare("s") || !input.compare("w") || !input.compare("e")))
    {
      moveRooms(vec[0]);
    }
    else if(vec.size() == 1 && !input.compare("i"))
    {
      printInventory();
    }
    else if(vec.size() == 2 && !vec[0].compare("take"))
    {
      takeItem(vec[1]);
    }
    else if(vec.size() == 2 && !input.compare("open exit"))
    {
      openExit();
    }
    else if(vec.size() == 2 && !vec[0].compare("open"))
    {
      openContainer(vec[1]);
    }
    else if(vec.size() == 2 && !vec[0].compare("read"))
    {
      readItem(vec[1]);
    }
    else if(vec.size() == 2 && !vec[0].compare("drop"))
    {
      dropItem(vec[1]);
    }
    else if(vec.size() == 4 && !vec[0].compare("put") && !vec[2].compare("in"))
    {
      putItemInContainer(vec[1], vec[3]);
    }
    else if(vec.size() == 3 && !vec[0].compare("turn") && !vec[1].compare("on"))
    {
      turnOnItem(vec[2]);
    }
    else if(vec.size() == 4 && !vec[0].compare("attack") && !vec[2].compare("with"))
    {
      attackCreature(vec[1], vec[3]);
    }
    else
    {
      cout << "Error" << endl;
    }
  } while(!gameOver);
}

void Map::moveRooms(string direction)
{
  for(int i = 0; i < currentRoom->borders.size(); i++)
  {
    if(!currentRoom->borders[i]->direction.compare(direction))
    {
      for(int j = 0; j < rooms.size(); j++)
      {
        if(!rooms[j]->name.compare(currentRoom->borders[i]->name))
        {
          currentRoom = rooms[j];
          return;
        }
      }
    }

    if(i + 1 == currentRoom->borders.size())
    {
      cout << "Can't go that way" << endl;
    }
  }
}

void Map::printInventory()
{
  cout << "Inventory: ";

  if(inventory.size() == 0)
  {
    cout << "empty";
  }
  else if(inventory.size() == 1)
  {
    cout << inventory[0];
  }
  else
  {
    int i = 0;

    while(i != inventory.size() - 1)
    {
      cout << inventory[i++] << ", ";
    }

    cout << inventory[i];
  }

  cout << endl;
}

void Map::takeItem(string item)
{
  for(int i = 0; i < currentRoom->items.size(); i++)
  {
    if(!currentRoom->items[i].compare(item))
    {
      cout << "Item " << item << " added to inventory." << endl;
      inventory.push_back(item);

      currentRoom->items.erase(currentRoom->items.begin() + i);
      return;
    }
  }

  // TODO
  for(int i = 0; i < currentRoom->containers.size(); i++)
  {
    for(int j = 0; j < containers.size(); j++)
    {
      if(!currentRoom->containers[i].compare(containers[j]->name))
      {
        for(int k = 0; k < containers[j]->items.size(); k++)
        {
          if(!containers[j]->items[k].compare(item) && containers[j]->open)
          {
            cout << "Item " << item << " added to inventory." << endl;

            inventory.push_back(item);
            containers[j]->items.erase(containers[j]->items.begin() + k);
            return;
          }
        }
      }
    }
  }

  cout << "Error" << endl;
}

void Map::openExit()
{
  if(!currentRoom->type.compare("exit"))
  {
    cout << "Game Over" << endl;
    gameOver = 1;
  }
}

void Map::openContainer(string container)
{
  for(int i = 0; i < currentRoom->containers.size(); i++)
  {
    if(currentRoom->containers[i].compare(container))
    {
      for(int j = 0; j < containers.size(); j++)
      {
        if(!containers[j]->name.compare(container) && !containers[j]->open)
        {
          containers[j]->open = 1;

          if(containers[j]->items.size() == 0)
          {
            cout << container << " is empty." << endl;
            return;
          }

          cout << "Container " << container << " contains ";

          int size = containers[j]->items.size();

          for(int k = 0; k < size - 1; k++)
          {
            cout << containers[j]->items[k] << ", ";
          }

          cout << containers[j]->items[size - 1] << endl;
        }

        // May add feature later

        //else if(!containers[j]->name.compare(container))
        //{
        //  for(int k = 0; k < containers[j]->items.size(); k++)
        //  {
        //    cout << containers[j]->items[k] << endl;
        //  }
        //}
      }
    }
  }
}

void Map::readItem(string item)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(!inventory[i].compare(item))
    {
      for(int j = 0; j < items.size(); j++)
      {
        if(!item.compare(items[j]->name))
        {
          if(!items[j]->writing.compare(""))
          {
            cout << "Nothing written." << endl;
            return;
          }

          cout << items[j]->writing << endl;
          return;
        }
      }
    }
  }
}

void Map::dropItem(string item)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(!inventory[i].compare(item))
    {
      inventory.erase(inventory.begin() + i);

      currentRoom->items.push_back(item);

      cout << item << " dropped" << endl;

      return;
    }
  }
}

void Map::putItemInContainer(string item, string container)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(!inventory[i].compare(item))
    {
      for(int j = 0; j < currentRoom->containers.size(); j++)
      {
        if(!currentRoom->containers[j].compare(container))
        {
          for(int k = 0; k < containers.size(); k++)
          {
            if(!containers[k]->name.compare(container) && containers[k]->open)
            {
              containers[k]->setItem(item);

              inventory.erase(inventory.begin() + i);

              currentRoom->containers.push_back(item);

              cout << "Item " << item << " added to " << container << endl;
            }
          }
        }
      }
    }
  }
}

void Map::turnOnItem(string item)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(!inventory[i].compare(item))
    {
      for(int j = 0; j < items.size(); j++)
      {
        if(!items[j]->name.compare(item) && !items[j]->turnon->on)
        {
          items[j]->turnon->on = 1;

          cout << "You activate the " << item << endl;
          cout << items[j]->turnon->print << endl;
          // Do item action
          return;
        }
        else
        {
          cout << item << " is already on." << endl;
        }
      }
    }
  }

  cout << "Item not found" << endl;
}

void Map::attackCreature(string creature, string item)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(!inventory[i].compare(item))
    {
      for(int j = 0; j < creatures.size(); j++)
      {
        if(!creatures[j]->name.compare(creature))
        {
          for(int k = 0; k < currentRoom->creatures.size(); k++)
          {
            if(!currentRoom->creatures[k].compare(creature))
            {
              cout << "You assault the " << creature << " with the " << item << endl;

              for(int l = 0; l < creatures[j]->vulnerabilities.size(); l++)
              {
                if(!creatures[j]->vulnerabilities[l].compare(item))
                {
                  // execute attack elements
                  cout << "ATTACK" << endl;
                }
              }
            }
          }
        }
      }
    }
  }
}

#endif // __MAP_H_
