#include "Weapon.h"


/*********************************************************************************************************
 * Weapon Implementation
 *********************************************************************************************************/
Weapon::Weapon(const std::string& n, int d)
: Item{n, Item::Type::WEAPON},
  damage{d} {}

void Weapon::addDamage(int d) {
  damage += d;
}

int Weapon::getDamage() const {
  return damage;
}

bool Weapon::operator>(const Weapon& rightSide) {
  return damage > rightSide.damage;
}