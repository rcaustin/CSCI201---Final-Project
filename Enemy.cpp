#include "Enemy.h"


/*********************************************************************************************************
 * Base Class Implementation
 *********************************************************************************************************/
Enemy::Enemy(int h, int d)
: health{h},
  damage{d} {}

std::random_device Enemy::device;
std::mt19937 Enemy::random_generator{device()};
std::uniform_int_distribution<std::mt19937::result_type> Enemy::pick3{1,3};

Enemy::~Enemy() {}

void Enemy::takeDamage(int amount) {
  health -= amount;
}

bool Enemy::isAlive() const {
  return health > 0;
}

int Enemy::dealDamage(int multiplier) const {
  return damage + (5 * multiplier);
}

/*********************************************************************************************************
 * Derived Class Implementations
 *********************************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Goblin
Goblin::Goblin()
  : Enemy{25, 5} {}

Goblin::~Goblin() {}

void Goblin::describe() const {
  std::cout << "You see a wicked goblin flashing a steel knife lurking in the\nshadows.\n";
}

int Goblin::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Goblin slashes at you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Goblin lunges and stabs you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Goblin spins around like mad, slashing you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Goblin slashes at you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Orc
Orc::Orc()
  : Enemy{50, 10} {}

Orc::~Orc() {}

void Orc::describe() const {
  std::cout << "A mighty orc blocks your way swinging a huge battleaxe.\n";
}

int Orc::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Orc swings its battleaxe at you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Orc kicks you in the gut for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Orc spins around like mad, slashing you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Orc swings its battleaxe at you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dragon
Dragon::Dragon()
: Enemy{100, 25} {}

Dragon::~Dragon() {}

void Dragon::describe() const {
  std::cout << "You see before you a fierce red dragon with shining scales and a\nrazor-sharp tail.\n";
}

int Dragon::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Dragon claws at you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Dragon swipes at you with its tail " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Dragon blasts a gout of flame at you " << damage << " damage\n";
      break;
    default:
      std::cout << "The Dragon claws at you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Beholder
Beholder::Beholder()
: Enemy{60, 15} {}

Beholder::~Beholder() {}

void Beholder::describe() const {
  std::cout << "You spot a bulbous, writhing mass of gray flesh covered in\n"
               "foot-long tentacle-like stalks, each ending in a differently\n"
               "colored eye.\n";
}

int Beholder::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Beholder zaps you with an Electric Eye " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Beholder freezes you with a Chilling Eye " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Beholder curses you with the Evil Eye for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Beholder zaps you with an Electric Eye " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Kobold
Kobold::Kobold()
: Enemy{40, 10} {}

Kobold::~Kobold() {}

void Kobold::describe() const {
  std::cout << "You find what looks like a cross between a lizard and a person\n"
               "waving a sword in your direction.\n";
}

int Kobold::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Kobold slashes at you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Kobold lunges and stabs you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Kobold spins around like mad, slashing you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Kobold slashes at you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Basilisk
Basilisk::Basilisk()
: Enemy{70, 15} {}

Basilisk::~Basilisk() {}

void Basilisk::describe() const {
  std::cout << "You quickly avert your gaze after almost locking eyes with the\n"
               "deadly basilisk, a mighty lizard whose gaze turns people to stone.\n";
}

int Basilisk::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Basilisk swipes you with its tail for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Basilisk lunges and bites you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Basilisk catches your eye, starting to petrify you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Basilisk swipes at you with its tail for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Minotaur
Minotaur::Minotaur()
: Enemy{60, 15} {}

Minotaur::~Minotaur() {}

void Minotaur::describe() const {
  std::cout << "You hear the scrape of hooves on the floor and a fierce growl...\n"
               "the minotaur stands ready to charge.\n";
}

int Minotaur::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Minotaur tackles you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Minotaur charges at you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Minotaur lifts you and tosses you like a ragdoll for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Minotaur tackles you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dragonfly
Dragonfly::Dragonfly()
: Enemy{35, 15} {}

Dragonfly::~Dragonfly() {}

void Dragonfly::describe() const {
  std::cout << "A buzzing fills your ears as you catch a glimpse of a giant\n"
               "dragonfly zooming toward you.\n";
}

int Dragonfly::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Dragonfly tackles you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Dragonfly darts in and bites you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Dragonfly spits acid at you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Dragonfly tackles you for " << damage << " damage.\n";
      break;
  }
  return damage;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Titan
Titan::Titan()
: Enemy{80, 25} {}

Titan::~Titan() {}

void Titan::describe() const {
  std::cout << "Looming high above you stands a mighty titan ready to strike with\n"
               "lightning and thunder.\n";
}

int Titan::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Titan punches you for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Titan grabs and squeezes you for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Titan launches a lightning bolt at you for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Titan punches you for " << damage << " damage.\n";
      break;
  }
  return damage;  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ShadowQueen
ShadowQueen::ShadowQueen()
: Enemy{120, 30} {}

ShadowQueen::~ShadowQueen() {}

void ShadowQueen::describe() const {
  std::cout << "Your sight grows dim and your body weak as you come face to face\n"
               "with the dreaded Shadow Queen!\n";
}

int ShadowQueen::attack() const {
  int choice = pick3(random_generator);
  int damage = dealDamage(choice);
  switch (choice) {
    case 1:
      std::cout << "The Shadow Queen hexes your blood for " << damage << " damage.\n";
      break;
    case 2:
      std::cout << "The Shadow Queen envelops you in darkness for " << damage << " damage.\n";
      break;
    case 3:
      std::cout << "The Shadow Queen erases a precious memory for " << damage << " damage\n";
      break;
    default:
      std::cout << "The Shadow Queen hexes your blood for " << damage << " damage.\n";
      break;
  }
  return damage; 
}