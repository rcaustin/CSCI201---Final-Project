#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"


/*********************************************************************************************************
 * Player Interface
 *********************************************************************************************************/
class Player {
public:
  Player();
  ~Player();

  int dealDamage() const;
  void takeDamage(int amount);

  bool isAlive() const;

  void usePotion(int index);
  void giveLoot(Item* loot);
  void printStatus() const;

  // Magic and Spells
  int  channelSpell(unsigned long manaCost);
  void castFizzle();
  void castHeal(int power);
  int  castMissile(int power);
  void castRestore();
  void castEnchantWeapon();
  void castEnchantArmor();
  int  castLightningBolt();
  void castBackfire();
  int  castMeteor();

private:
  // Player Attributes
	int health;
  int mana;

  // Player Equipment
  Weapon* weapon;
  Armor* armor;
	std::vector<Potion*> potions;

  // Constants
  static const int MAX_HEALTH{100};
  static const int MAX_MANA{15};

  // Random Number Generation
  static std::random_device device;
  static std::mt19937 random_generator;

  friend class Potion;
  
  void heal(int amount);
  void recharge(int amount);
  void enhanceWeapon(int amount);
  void enhanceArmor(int amount);
};

template<typename T>
bool isUpgrade(T* equipped, T* looted) {
  return (*looted) > (*equipped);
}

#endif // PLAYER_H