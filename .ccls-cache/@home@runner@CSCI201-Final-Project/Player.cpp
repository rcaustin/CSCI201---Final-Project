#include "Player.h"


/*********************************************************************************************************
 * Player Implementation
 *********************************************************************************************************/
Player::Player() 
: health{MAX_HEALTH},
  mana{MAX_MANA},
  weapon{new Weapon{"Pocket Knife", 5}},
  armor{new Armor{"Traveling Cloak", 5}} {}

std::random_device Player::device;
std::mt19937 Player::random_generator{device()};

Player::~Player() {
  if (weapon != nullptr) {
    delete weapon;
    weapon = nullptr;
  }
  if (armor != nullptr) {
    delete armor;
    armor = nullptr;
  }
}

int Player::dealDamage() const {
  std::cout << "You attack your foe with your " << weapon->getName()
            << " for " << weapon->getDamage() << " damage.\n";
  return weapon->getDamage();
}

void Player::takeDamage(int amount) {
  int damage = std::max(0, (amount - armor->getDefense()));
  std::cout << "Your armor blocks " << armor->getDefense()
            << ", and you take " << damage << " damage.\n";
  health -= damage;
}

bool Player::isAlive() const {
  return health > 0;
}

void Player::usePotion(int index) {
  if (index < 0 || ((index + 1) > potions.size()))
    std::cout << "You don't have an item there.\n";
  else {
    // Apply the Potion Effect
    std::cout << "You use your " << potions[index]->getName() << ".\n";
    potions[index]->applyEffect(this);

    // Remove the Potion
    delete potions[index];
    potions[index] = nullptr;
    potions.erase(potions.begin()+index);
  }
}

void Player::giveLoot(Item* loot) {
  if (loot != nullptr) {
    if (loot->getType() == Item::Type::WEAPON) {
      if (isUpgrade<Weapon>(weapon, (Weapon*)loot))
        weapon = (Weapon*)loot;
    }
    else if (loot->getType() == Item::Type::ARMOR) {
      if (isUpgrade<Armor>(armor, (Armor*)loot))
        armor = (Armor*)loot;
    }
    else
      potions.push_back((Potion*)loot);
  }
}

void Player::printStatus() const {
  std::cout << "-------------------------------------------------------------------\n"
            << "| Status\n"
            << "-------------------------------------------------------------------\n";
  
  // Print Health Status
  std::cout << "| Health:  " << "[" << health << "] ";
  if (health < 21)
    std::cout << "Severely Wounded\n";
  else if (health < 41)
    std::cout << "Hurting Bad\n";
  else if (health < 61)
    std::cout << "Scraped Up\n";
  else if (health < 81)
    std::cout << "Winded\n";
  else
    std::cout << "Going Strong\n";
  
  // Print Mana Status
  std::cout << "| Mana:    " << "[" << mana << "] "; 
  if (mana < 1)
    std::cout << "Dim\n";
  else if (mana < 5)
    std::cout << "Fading\n";
  else if (mana < 10)
    std::cout << "Glowing\n";
  else
    std::cout << "Radiant\n";

  // Print Equipment Status
  std::cout << "| Weapon: " << " [" << weapon->getDamage() << "] " << weapon->getName() << "\n"
            << "| Armor:  " << " [" << armor->getDefense() << "] " << armor->getName()  << "\n";
  std::cout << "| Potions:\n";
  for (size_t i = 0; i < potions.size(); ++i) {
    std::cout << "| -------- [#" << i << "] " 
              << potions[i]->getName()
              << " "
              << "(" << potions[i]->getDescription() << ")"
              << "\n";
  }
  std::cout << "-------------------------------------------------------------------\n";
}

int Player::channelSpell(unsigned long manaCost) {
  if (manaCost > mana) {
    std::cout << "You don't have enough mana to cast that spell.\n";
    return 0;
  } else {
    std::cout << "You channel " << manaCost << " mana into a spell...\n";
    mana -= manaCost;
    std::uniform_int_distribution<std::mt19937::result_type> range{0, manaCost};
    return range(random_generator);
  }
}

void Player::castFizzle() {
  std::cout << "Your spell fizzles out with no effect.\n";
}

void Player::castHeal(int power) {
  static const int MULTIPLIER = 5;
  std::cout << "Your body glows with magical energy healing your wounds.\n";
  heal(power * MULTIPLIER);
}

int Player::castMissile(int power) {
  static const int MULTIPLIER = 5;
  int damage = power * MULTIPLIER;
  std::cout << power << " bolts of magical energy erupt from your hands and blast the\n"
            << "monster for " << damage << " damage!\n";
  return damage;
}

void Player::castRestore() {
  std::cout << "Mana courses through your body, restoring you to peak physical condition.\n"
            << "Your health and mana are now full.\n";
  health = MAX_HEALTH;
  mana = MAX_MANA;
}

void Player::castEnchantWeapon() {
  static const int AMOUNT = 5;
  std::cout << "Your " << weapon->getName() << " glows with magical energy gaining "
            << AMOUNT << " damage.\n";
  enhanceWeapon(AMOUNT);
}

void Player::castEnchantArmor() {
  static const int AMOUNT = 5;
  std::cout << "Your " << armor->getName() << " glows with magical energy gaining "
            << AMOUNT << " defense.\n";
  enhanceArmor(AMOUNT);
}

int Player::castLightningBolt() {
  std::uniform_int_distribution<std::mt19937::result_type> range{10, 80};
  int damage = range(random_generator);
  std::cout << "Magical energy arcs between your fingers and rips toward your foe\n"
            << "for " << damage << " damage.\n";
  return damage;
}

void Player::castBackfire() {
  std::cout << "You channel your arcane energy but lose control in the process.\n"
            << "Your spell backfires for 10 damage.\n";
  health -= 10;
}

int Player::castMeteor() {
  static const int DAMAGE = 999;
  std::cout << "You weave your arcane energy into a complex pattern, reaching\n"
            << "up to pull a meteor from the heavens, launching it at your foe\n"
            << "for a catastrophic " << DAMAGE << " damage!\n";
  return DAMAGE;
}

void Player::heal(int amount) {
  health = std::min(health + amount, MAX_HEALTH);
  std::cout << "Your wounds heal, and your health is now " << health << ".\n";
}

void Player::recharge(int amount) {
  mana = std::min(mana + amount, MAX_MANA);
  std::cout << "You feel magical power swell within you; your mana is now " << mana << ".\n";
}

void Player::enhanceWeapon(int amount) {
  weapon->addDamage(amount);
  std::cout << "Your " << weapon->getName() << " now does "
            << weapon->getDamage() << " damage.\n";
}

void Player::enhanceArmor(int amount) {
  armor->addDefense(amount);
  std::cout << "Your " << armor->getName() << " now has " 
            << armor->getDefense() << " defense.\n";
}