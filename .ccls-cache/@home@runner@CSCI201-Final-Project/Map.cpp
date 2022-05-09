#include "Map.h"

#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"


/*********************************************************************************************************
 * Map Implementation
 *********************************************************************************************************/

Map::Map() {
  wizardTowerStart = new Room{"Wizard's Tower",
                              "The wizard's tower has bookshelves full of musical scores, endless\n"
                              "walls of instruments, and a roaring fireplace in the corner. The\n"
                              "wizard strokes his beard thoughtfully before speaking, \"I seem to\n"
                              "have lost my Mystical Electric Guitar. Without it, tonight's show\n"
                              "is doomed to mediocrity. If you could find it for me, you will be\n"
                              "handsomely rewarded.\""};
  
  wizardTowerEnd   = new Room{"The Wizard Tower",
                              "You return triumphant holding the Mystical Electric Guitar.\n"
                              "The wizard thanks you and gives you his spellbook that you\n"
                              "might one day become a powerful wizard yourself. "
                              "Congratulations! You have won!"};
  
  townGreen    = new Room{"Town Green",
                          "From the town green, you can access the merchant's shop and\n"
                          "the dark forest. You'll need to find the wizard's guitar before\n"
                          "you go back to the tower."};
  
  itemShop     = new Room{"Item Shop",
                          "Inside the merchant's shop you find shelves littered with\n"
                          "various bits and bobs and useful things. The shopkeeper\n"
                          "greets you with a smile and offers you a treasure to help you\n"
                          "on your quest.",
                          new Potion{"Draught of Health", 50, "Restore 50 Health"}};

  blacksmith   = new Room{"Blacksmith's Workshop",
                          "You hear the ringing of hammer on anvil as you step into the\n"
                          "blacksmith's workshop. She nods in your direction and offers you\n"
                          "her old hammer to help you on your quest.",
                          new Weapon{"Old Hammer", 15}};

  tailor       = new Room{"Leatherworker's Shop",
                          "As you cross the threshold into the leatherworker's shop, the aroma\n"
                          "of pungent oils and acrid solvents stings your nose. The old man\n"
                          "looks up from his tanning rack and gestures toward a leather\n"
                          "doublet to aid you on your journey.",
                          new Armor{"Leather Doublet", 10}};

  darkForest   = new Room{"Dark Forest",
                          "Gnarled branches twist upward to block out the sun. In the dim\n"
                          "light of the dark forest you can make out three paths forward:\n"
                          "south toward a series of damp caves, further west to the sticking\n"
                          "bog, or north toward the Cliffs of Insanity."};
  
  dampCavern   = new Room{"Damp Cavern",
                          "A dimly lit series of winding passages worn through the rock leads\n"
                          "to a larger chamber with flickering torches on the walls.",
                          new Potion{"Draught of Spirit", 7, "Restore 7 Mana"},
                          new Goblin};
  
  orcWarrens   = new Room{"Orc Warrens",
                          "The caves become drier further in, and crude furnishings populate\n"
                          "the almost livable home of the orcs.",
                          new Potion{"Viper's Venom", 5, "Add 5 Damage to Weapon"},
                          new Orc};
  
  labyrinth    = new Room{"Twisting Labyrinth",
                          "The caves give way to what could be an endless maze of twisted,\n"
                          "criss-crossing halls of the labyrinth. Getting lost is but one\n"
                          "of many dangers in the home of the dreaded minotaur.",
                          new Armor{"Shining Platemail", 15},
                          new Minotaur};
  
  stickingBog  = new Room{"Stinking Bog",
                          "The ground becomes soft and muddy as the forest gives way\n"
                          "to a bog. Dense undergrowth makes it difficult to see more\n"
                          "than a dozen feet in front of you.",
                          new Potion{"Draught of Health", 50, "Restore 50 Health"},
                          new Kobold};

  suckingSwamp = new Room{"Sucking Swamp",
                          "The swamp resists every footstep with sucking mud and muck\n"
                          "as you push on through the foul-smelling wetlands.",
                          new Potion{"Stoneskin", 5, "Add 5 Defense to Armor"},
                          new Basilisk};
  
  putridMire   = new Room{"Putrid Mire",
                          "The swamp is darkest this far in, and it feels as if the trees\n"
                          "themselves reach out to grab you. Legends say a dangerous black\n"
                          "dragon nests within the murky waters.",
                          new Weapon{"Knight's Sword", 25},
                          new Dragon};
  
  cliffs       = new Room{"Cliffs of Insanity",
                          "Aptly named, these cliffs give way to a dizzying drop. You will\n"
                          "need to mind your footing as you travel this close to the edge.",
                          new Potion{"Elixir of Life", 100, "Restore All Health"},
                          new Dragonfly};
  
  barrens      = new Room{"Blasted Barrens",
                          "This land features very little vegetation and almost no animal\n"
                          "life; the wizard says an old sorceress, mad for power, stripped the\n"
                          "energy from the earth itself in her pursuit of immortality.",
                          new Potion{"Draught of Spirit", 7, "Restore 7 Mana"},
                          new Beholder};
  
  battlement   = new Room{"Crumbling Battlement",
                          "You venture upon the crumble ruins of an ancient fort: the remnant\n"
                          "of a legendary battle between the forces of good and evil.",
                          new Potion{"Elixir of Arcana", 15, "Restore All Mana"},
                          new Titan};
  
  darkTower    = new Room{"Dark Tower",
                          "You ascend to the highest room in the dark, foreboding tower.\n"
                          "The very walls thrum with magical energy; this must be the home\n"
                          "of the dreaded Shadow Queen. In the far corner you spot your prize:\n"
                          "the wizard's Mystical Electric Guitar.",
                          nullptr, // No Treasure, Last Fight
                          new ShadowQueen};

  currentRoom = wizardTowerStart;
  connectRoomExits();
}

Map::~Map() {
  delete wizardTowerStart;
  delete wizardTowerEnd;
  delete townGreen;
  delete itemShop;
  delete darkForest;
  delete dampCavern;
  delete orcWarrens;
  delete labyrinth;
  delete stickingBog;
  delete suckingSwamp;
  delete putridMire;
  delete cliffs;
  delete barrens;
  delete battlement;
  delete darkTower;
}

Room* Map::getCurrentRoom() const {
  return currentRoom;
}

bool Map::isFinalRoom() const {
  return currentRoom == wizardTowerEnd;
}

void Map::exitRoom(const std::string& direction) {
  Room* nextRoom = nullptr;
       if (direction == "NORTH") nextRoom = currentRoom->exit(Direction::NORTH);
  else if (direction == "SOUTH") nextRoom = currentRoom->exit(Direction::SOUTH);
  else if (direction == "EAST")  nextRoom = currentRoom->exit(Direction::EAST);
  else if (direction == "WEST")  nextRoom = currentRoom->exit(Direction::WEST);
  
  if (nextRoom != nullptr) {
    currentRoom = nextRoom;
    currentRoom->describe();
  }
}

void Map::connectRoomExits() {
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // Town Rooms
  townGreen->setExit(Direction::EAST, itemShop);
  itemShop->setExit(Direction::WEST, townGreen);
  
  townGreen->setExit(Direction::WEST, darkForest);
  darkForest->setExit(Direction::EAST, townGreen);

  townGreen->setExit(Direction::NORTH, blacksmith);
  blacksmith->setExit(Direction::SOUTH, townGreen);

  townGreen->setExit(Direction::SOUTH, tailor);
  tailor->setExit(Direction::NORTH, townGreen);

  wizardTowerStart->setExit(Direction::SOUTH, townGreen);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // Dungeon Rooms
  // Dark Forest is Entry-Point to Dungeon and Branches to Three Paths
  // Easy Path
  darkForest->setExit(Direction::SOUTH, dampCavern);            // Forward
  dampCavern->setExit(Direction::SOUTH, orcWarrens, true);
  orcWarrens->setExit(Direction::WEST, labyrinth, true);
  labyrinth->setExit(Direction::EAST, orcWarrens);              // Backward
  orcWarrens->setExit(Direction::NORTH, dampCavern);
  dampCavern->setExit(Direction::NORTH, darkForest);

  // Medium Path
  darkForest->setExit(Direction::WEST, stickingBog);            // Forward
  stickingBog->setExit(Direction::WEST, suckingSwamp, true);
  suckingSwamp->setExit(Direction::WEST, putridMire, true);
  putridMire->setExit(Direction::EAST, suckingSwamp);           // Backward
  suckingSwamp->setExit(Direction::EAST, stickingBog);
  stickingBog->setExit(Direction::EAST, darkForest);

  // Hard Path (Final Boss Path)
  darkForest->setExit(Direction::NORTH, cliffs);                // Forward
  cliffs->setExit(Direction::NORTH, barrens, true);
  barrens->setExit(Direction::WEST, battlement, true);
  battlement->setExit(Direction::NORTH, darkTower, true);
  battlement->setExit(Direction::EAST, barrens);                // Backward
  barrens->setExit(Direction::SOUTH, cliffs);
  cliffs->setExit(Direction::SOUTH, darkForest);
  darkTower->setExit(Direction::NORTH, wizardTowerEnd, true);   // Return Home to Complete Quest
}