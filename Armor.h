#ifndef ARMOR_H
#define ARMOR_H

#include <string>

#include "Item.h"


/*********************************************************************************************************
 * Armor Interface
 *********************************************************************************************************/
class Armor : public Item {
public:
  Armor(const std::string& n, int d);
  Armor();

  void addDefense(int d);

  int getDefense() const;

  bool operator>(const Armor& rightSide);

private:
  int defense;
};

#endif // ARMOR_H