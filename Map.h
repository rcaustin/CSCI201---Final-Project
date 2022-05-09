#ifndef MAP_H
#define MAP_H

#include <string>

#include "Room.h"


/*********************************************************************************************************
 * Map Interface
 *********************************************************************************************************/

class Map {
public:
  Map();
  ~Map();

  Room* getCurrentRoom() const;
  bool isFinalRoom() const;

  void exitRoom(const std::string& direction);

private:
  // Player's Current Location
  Room* currentRoom;

  // Game Start
  Room* wizardTowerStart;
  
  // Game End
  Room* wizardTowerEnd;

  // Town Rooms
  Room* townGreen;
  Room* itemShop;
  Room* blacksmith;
  Room* tailor;

  // Dungeon Rooms
  Room* darkForest;
  Room* dampCavern;
  Room* orcWarrens;
  Room* labyrinth;
  Room* stickingBog;
  Room* suckingSwamp;
  Room* putridMire;
  Room* cliffs;
  Room* barrens;
  Room* battlement;
  Room* darkTower;

  void connectRoomExits();
};

#endif // MAP_H