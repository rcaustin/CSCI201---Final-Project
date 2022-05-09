#ifndef POTION_H
#define POTION_H

#include <string>

#include "Item.h"


class Player;

/*********************************************************************************************************
 * Potion Interface
 *********************************************************************************************************/
class Potion : public Item {
public:
  Potion(const std::string& n, int v, const std::string& d);

  int getValue() const;
  std::string getDescription() const;

  void applyEffect(Player* player) const;

private:
  int value;
  std::string description;
};

#endif // POTION_H