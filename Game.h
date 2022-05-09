#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"
#include "Map.h"


class Game {
public:
  Game();

  void start();
  void quit();
  void help() const;
  void go(const std::string& direction);
  void take();
  void look() const;
  void status() const;
  void fight();
  void use(const std::string& choice);
  void magic(const std::string& mana);

  bool stillPlaying() const;

private:
  bool isRunning;
  Player player;
  Map map;

  bool isNumeric(const std::string& string) const;
  int stringToInt(const std::string& string) const;
};

#endif // GAME_H