#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <sstream>


/* Possible Commands:
 * QUIT
 * HELP
 * TAKE
 * FIGHT
 * LOOK
 * GO [DIRECTION]
 * USE [POTION #]
 */

struct Command {
  std::string Action;
  std::string Object;
};

Command parseCommand();

#endif // COMMAND_H