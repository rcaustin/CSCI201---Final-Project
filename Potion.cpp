#include "Potion.h"

#include <iostream>

#include "Player.h"


/*********************************************************************************************************
 * Potion Implementation
 *********************************************************************************************************/
Potion::Potion(const std::string& n, int v, const std::string& d)
: Item{n, Item::Type::Potion},
  value{v},
  description{d} {}

int Potion::getValue() const {
  return value;
}

std::string Potion::getDescription() const {
  return description;
}

void Potion::applyEffect(Player* player) const {
  if ((name.compare("Draught of Health") == 0) || (name.compare("Elixir of Life") == 0))
    player->heal(value);
  else if ((name.compare("Draught of Spirit") == 0) || (name.compare("Elixir of Arcana") == 0))
    player->recharge(value);
  else if (name.compare("Viper's Venom") == 0)
    player->enhanceWeapon(value);
  else if (name.compare("Stoneskin") == 0)
    player->enhanceArmor(value);
}