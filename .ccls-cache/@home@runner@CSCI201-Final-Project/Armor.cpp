#include "Armor.h"


/*********************************************************************************************************
 * Armor Implementation
 *********************************************************************************************************/
Armor::Armor(const std::string& n, int d)
: Item{n, Item::Type::ARMOR},
  defense{d} {}

void Armor::addDefense(int d) {
  defense += d;
}

int Armor::getDefense() const {
  return defense;
}

bool Armor::operator>(const Armor& rightSide) {
  return defense > rightSide.defense;
}