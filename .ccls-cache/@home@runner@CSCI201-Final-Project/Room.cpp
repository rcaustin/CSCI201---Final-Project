#include "Room.h"

#include <algorithm>


/*********************************************************************************************************
 * Room Implementation
 *********************************************************************************************************/
Room::Room(const std::string& p_name, const std::string& p_description, Item* p_treasure, Enemy* p_monster)
  : name{p_name},
    description{p_description},
    guardedDirection{Direction::NORTH},
    monster{p_monster},
    treasure{p_treasure},
    northExit{nullptr},
    southExit{nullptr},
    eastExit{nullptr},
    westExit{nullptr} {}

Room::~Room() {
  if (monster != nullptr) {
    delete monster;
    monster = nullptr;
  }
  if (treasure != nullptr) {
    delete treasure;
    treasure = nullptr;
  }
}

void Room::setMonster(Enemy* enemy) {
  monster = enemy;
}

void Room::setTreasure(Item* item) {
  treasure = item;
}

void Room::setExit(Direction direction, Room* room, bool isGuarded) {
  if (isGuarded)
    guardedDirection = direction;
  
  switch (direction) {
    case Direction::NORTH:
      northExit = room;
      break;
    case Direction::SOUTH:
      southExit = room;
      break;
    case Direction::EAST:
      eastExit = room;
      break;
    case Direction::WEST:
      westExit = room;
      break;
    default:
      break;
  }
}

Enemy* Room::getMonster() const {
  return monster;
}

void Room::describe() const {
  // Describe Room Flavor Text
  std::cout << "-------------------------------------------------------------------\n"
            << "| You are in the " << name << "\n"
            << "-------------------------------------------------------------------\n"
            << "\n" << description << "\n\n";

  // Describe Treasure if Present
  if (treasure != nullptr)
    std::cout << "There is treasure in here: " << treasure->getName() << "!\n\n";
  
  // Describe Enemy if Present
  if (monster != nullptr) {
    std::cout << "<!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=!>\n";
    monster->describe();
    std::cout << "<!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=!>\n\n";
  }
  
  // Describe Exits if Any Exist
  if ((northExit != nullptr) || (southExit != nullptr) ||
      (eastExit  != nullptr) || (westExit  != nullptr)) {
    std::cout << "-------------------------------------------------------------------\n"
              << "| Room Exits\n"
              << "-------------------------------------------------------------------\n";
    if (northExit != nullptr)
      std::cout << "| To the [NORTH] you see the " << northExit->name << "\n";
    if (southExit != nullptr)
      std::cout << "| To the [SOUTH] you see the " << southExit->name << "\n";
    if (eastExit != nullptr)
      std::cout << "| To the [EAST] you see the " << eastExit->name << "\n";
    if (westExit != nullptr)
      std::cout << "| To the [WEST] you see the " << westExit->name << "\n";
  
    std::cout << "-------------------------------------------------------------------\n";
  }
}

Room* Room::exit(Direction direction) const {
  // Player Trying to Leave, Monster Blocking Exit
  if (monster != nullptr && direction == guardedDirection) {
    std::cout << "The monster is guarding that exit!\n";
    return nullptr;
  }

  // Unblocked; Check if Direction is Valid
  switch (direction) {
    case Direction::NORTH:
      if (northExit != nullptr) return northExit;
      break;
    case Direction::SOUTH:
      if (southExit != nullptr) return southExit;
      break;
    case Direction::EAST:
      if (eastExit != nullptr) return eastExit;
      break;
    case Direction::WEST:
      if (westExit != nullptr) return westExit;
      break;
    default:
      break;
  }
  // No Exit in Chosen Direction
  std::cout << "There is no exit that way!\n";
  return nullptr;
}

void Room::slayMonster() {
  monster = nullptr;
  std::cout << "You have vanquished the monster!\n";
}

Item* Room::takeLoot() {
  if (monster != nullptr) {
    std::cout << "The monster is still guarding the treasure!\n";
    return nullptr;
  } else if (treasure == nullptr) {
    std::cout << "There is no treasure in this room.\n";
    return nullptr;
  } else {
    std::cout << "You take the " << treasure->getName() << ".\n";
    Item* loot = treasure;
    treasure = nullptr;
    return loot;
  }  
}