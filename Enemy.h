#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <random>
#include <string>


/*********************************************************************************************************
 * Base Class
 *********************************************************************************************************/
class Enemy {
public:
  Enemy(int h, int d);
  virtual ~Enemy();

  virtual void describe() const = 0;
  virtual int attack() const = 0;

  void takeDamage(int amount);
  bool isAlive() const;

protected:
	int health;
  int damage;
  std::string description;

  static std::random_device device;
  static std::mt19937 random_generator;
  static std::uniform_int_distribution<std::mt19937::result_type> pick3;

  int dealDamage(int multiplier) const;
};

/*********************************************************************************************************
 * Derived Classes
 *********************************************************************************************************/
class Goblin: public Enemy {
public:
  Goblin();
  ~Goblin();

  void describe() const;
  int attack() const;
};

class Orc: public Enemy {
public:
  Orc();
  ~Orc();

  void describe() const;
  int attack() const;
};

class Dragon: public Enemy {
public:
  Dragon();
  ~Dragon();

  void describe() const;
  int attack() const;
};

class Beholder: public Enemy {
public:
  Beholder();
  ~Beholder();

  void describe() const;
  int attack() const;
};

class Kobold: public Enemy {
public:
  Kobold();
  ~Kobold();

  void describe() const;
  int attack() const;
};

class Basilisk: public Enemy {
public:
  Basilisk();
  ~Basilisk();

  void describe() const;
  int attack() const;
};

class Minotaur: public Enemy {
public:
  Minotaur();
  ~Minotaur();

  void describe() const;
  int attack() const;
};

class Dragonfly: public Enemy {
public:
  Dragonfly();
  ~Dragonfly();

  void describe() const;
  int attack() const;
};

class Titan: public Enemy {
public:
  Titan();
  ~Titan();

  void describe() const;
  int attack() const;
};

class ShadowQueen: public Enemy {
public:
  ShadowQueen();
  ~ShadowQueen();

  void describe() const;
  int attack() const;
};

#endif // ENEMY_H
