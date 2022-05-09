#include <string>
#include <sstream>

/* Possible Commands
 * 
 * QUIT
 * HELP
 * GO [DIRECTION]
 * TAKE [ITEM IN ROOM]
 * FIGHT [ENEMY IN ROOM]
 * LOOK
 */

struct Command {
  std::string Action;
  std::string Object;
};

Command parseCommand();
