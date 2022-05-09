#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

#include "Enemy.h"
#include "Item.h"


/*********************************************************************************************************
 * Room Interface
 *********************************************************************************************************/
enum class Direction { NORTH, SOUTH, EAST, WEST };

class Room {
public:
  Room(const std::string& p_name, const std::string& p_description,
       Item* p_treasure=nullptr, Enemy* p_monster=nullptr);
  ~Room();

  void setMonster(Enemy* enemy);
  void setTreasure(Item* item);
  void setExit(Direction direction, Room* room, bool isGuarded = false);

  Enemy* getMonster() const;

  void describe() const;
  Room* exit(Direction direction) const;
  void slayMonster();

  Item* takeLoot();

private:
  std::string name;
	std::string description;
  Direction guardedDirection;
  Enemy* monster;
  Item* treasure;
  Room* northExit;
  Room* southExit;
  Room* eastExit;
  Room* westExit;
};

#endif // ROOM_H
