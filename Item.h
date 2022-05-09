#ifndef ITEM_H
#define ITEM_H

#include <string>


/*********************************************************************************************************
 * Base Class Interface
 *********************************************************************************************************/
class Item {
public:
  enum class Type { WEAPON, ARMOR, Potion };

  Item(const std::string& n, Type t);

  std::string getName() const;
  Type getType() const;

protected:
  std::string name;
  Type type;
};

#endif // ITEM_H