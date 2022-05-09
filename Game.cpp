#include "Game.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Enemy.h"
#include "Item.h"

/*********************************************************************************************************
 * Game Implementation
 *********************************************************************************************************/
Game::Game()
: isRunning{true} {
}

void Game::start() {
  std::cout << "-------------------------------------------------------------------\n"
            << "| Welcome to The Quest of Rock!\n";
  help();
  look();
}

void Game::quit() {
  isRunning = false;
  std::cout << "Closing the Game.\nThanks for playing!\n";
}

void Game::help() const {
  std::cout << "-------------------------------------------------------------------\n"
	          << "--- Game Rules ---\n"
	          << "-------------------------------------------------------------------\n"
	          << "-- Type go followed by a cardinal direction to move to another area\n"
	          << "-- Type use followed by a number to use a potion\n"
            << "-- Type fight to fight the monster in the current room\n"
            << "-- Type magic followed by the amount of mana to spend [0 - 15]\n"
            << "-- Type take to take the treasure in the current room\n"
            << "-- Type look to print a description of your current area\n"
            << "-- Type status to show your health, weapon, armor, and consumables\n"
            << "-- Type help to print these rules\n"
            << "-- Type quit to exit the game\n";
}

void Game::go(const std::string& direction) {
  map.exitRoom(direction);
}

void Game::take() {
  player.giveLoot(map.getCurrentRoom()->takeLoot());
}

void Game::look() const {
  map.getCurrentRoom()->describe();
}

void Game::status() const {
  player.printStatus();
}

void Game::fight() {
  Enemy* foe = map.getCurrentRoom()->getMonster();
  if (foe == nullptr)
    std::cout << "There is nothing here to fight.\n";
  else {
    // Player Attacks Monster First
    foe->takeDamage(player.dealDamage());
    
    // Monster Retaliates if Still Alive
    if (foe->isAlive()) {
      int damage = foe->attack();
      player.takeDamage(damage);

      // Game Ends if Player Dies
      if (!player.isAlive()) {
        std::cout << "You have died!\n";
        isRunning = false;
      }
    } else
      map.getCurrentRoom()->slayMonster();
  }
}

void Game::use(const std::string& input) {
  if (isNumeric(input))
    player.usePotion(stringToInt(input));
  else
    throw std::invalid_argument("Invalid Argument: Use Must Be Followed by a Non-Negative Number\n");
}

void Game::magic(const std::string& input) {
  Enemy* foe = map.getCurrentRoom()->getMonster();
  if (foe == nullptr) {
    std::cout << "There's no need for magic now.\n";
    return;
  } else {
    if (isNumeric(input)) {
      int spellPower = player.channelSpell(stringToInt(input));
      switch (spellPower) {
        // Power [0] = Fizzle
        case 0:
          player.castFizzle();
          break;
        // Power [1 - 3] = Heal
        case 1:
        case 2:
        case 3:
          player.castHeal(spellPower);
          break;
        // Power [4 - 6] = Missile
        case 4:
        case 5:
        case 6:
          foe->takeDamage(player.castMissile(spellPower));
          break;
        // Power [7] = ...
        case 7:
          player.castRestore();
          break;
        // Power [8 - 9] = Enchant Weapon
        case 8:
        case 9:
          player.castEnchantWeapon();
          break;
        // Power [10 - 11] = Enchant Armor
        case 10:
        case 11:
          player.castEnchantArmor();
          break;
        // Power [12] = Lightning Bolt
        case 12:
          foe->takeDamage(player.castLightningBolt());
        // Power [13] = Backfire
        case 13:
          player.castBackfire();
          break;
        // Power [14 - 15] = Meteor
        case 14:
        case 15:
          foe->takeDamage(player.castMeteor());
          break;
        default:
          break;
      }
    } else
    throw std::invalid_argument("Invalid Argument: Magic Must Be Followed by a Non-Negative Number\n");
  }
  if (!foe->isAlive())
    map.getCurrentRoom()->slayMonster();
}

bool Game::stillPlaying() const {
  return isRunning && !(map.isFinalRoom());
}

bool Game::isNumeric(const std::string& string) const {
  for (char const &character : string)
    if (std::isdigit(character) == 0)
      return false;
  return true;
}

int Game::stringToInt(const std::string& string) const {
  std::stringstream stream;
  int integer;
  stream << string;
  stream >> integer;
  return integer;
}