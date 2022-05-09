#include "Command.h"

#include <algorithm>
#include <iostream>


Command parseCommand() {
  std::cout << ">  ";
  std::string line;
  std::getline(std::cin, line);
  std::stringstream stream{line};
  
  Command command;
  stream >> command.Action;
  stream >> command.Object;
  std::transform(command.Action.begin(), command.Action.end(), command.Action.begin(), ::toupper);
  std::transform(command.Object.begin(), command.Object.end(), command.Object.begin(), ::toupper);
  return command;
}