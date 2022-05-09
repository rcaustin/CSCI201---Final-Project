#include <iostream>
#include <stdexcept>

#include "Command.h"
#include "Game.h"


int main() {
  Game game;
  game.start();
  try {
    while (game.stillPlaying()) {
      Command command = parseCommand();
      if (command.Action.compare("QUIT") == 0)
        game.quit();
      else if (command.Action.compare("HELP") == 0)
        game.help();
      else if (command.Action.compare("STATUS") == 0)
        game.status();
      else if (command.Action.compare("GO") == 0)
        game.go(command.Object);
      else if (command.Action.compare("TAKE") == 0)
        game.take();
      else if (command.Action.compare("LOOK") == 0)
        game.look();
      else if (command.Action.compare("FIGHT") == 0)
        game.fight();
      else if (command.Action.compare("USE") == 0)
        game.use(command.Object);
      else if (command.Action.compare("MAGIC") == 0)
        game.magic(command.Object);
      else
        std::cout << "Invalid Command\n";
    }
  } 
  catch (std::invalid_argument& e) {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}