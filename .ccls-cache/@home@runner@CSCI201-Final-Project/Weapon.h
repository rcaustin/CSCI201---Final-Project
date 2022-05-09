#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "Item.h"


/*********************************************************************************************************
 * Weapon Interface
 *********************************************************************************************************/
class Weapon : public Item {
public:
  Weapon(const std::string& n, int d);
  Weapon();

  void addDamage(int d);

  int getDamage() const;

  bool operator>(const Weapon& rightSide);

private:
  int damage;
};

#endif // WEAPON_H