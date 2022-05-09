#include "Item.h"

#include <algorithm>

#include "Player.h"


/*********************************************************************************************************
 * Base Class Implementation
 *********************************************************************************************************/
Item::Item(const std::string& n, Item::Type t)
: name{n},
  type{t} {}

std::string Item::getName() const {
  return name;
}

Item::Type Item::getType() const {
  return type;
}