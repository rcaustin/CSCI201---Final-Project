/*
#include <iostream>
#include <string>

//base class
class Consumable {
public:
  void setAddOn(int a) {
    addOn = a;
  }

 void setDescription(std::string d) {
    description = d;
  }

protected:
  int addOn;
  std::string description;
};

//derived classes
class BluePotion: public Consumable {
public:
  void message() {
    std::cout << "You get +10 points to your health.\n";
  }
};

class PurplePotion: public Consumable {
public:
  void message() {
     std::cout << "You get +20 points to your health.\n";
   }
};

class RedPotion: public Consumable {
public:
  void message() {
    std::cout << "Oops! This potion was poisonous! It took 10 points off your health!\n";
}
};

class EnergyPotion: public Consumable {
public:
  void message() {
    std::cout << "You get +10 points to your magic energy\n";
  }
};

class NeutralizingElixir: public Consumable {
public:
  void message() {
    std::cout << "You are immune to all attacks of your opponents untill you decide to attack them!\n";
  }
};

class ChaoticBomb: public Consumable {
public:
  void message() {
    std::cout << "Your opponent looses 10 health points!\n";
  }
};

class Venom: public Consumable {
public: 
  void message() {
    std::cout << "Your opponent looses 2 health points with each attack!\n";
  }
};

*/