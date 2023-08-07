#pragma once
#include "IOBase.h"

namespace FactoryMethod {
	class IMonster;

	class Player {
	private:
		string name = "";
		float hp = 100;
		float atk = 10;

	public:
		Player(const string& name, float hp, float atk)
			: name(name), hp(hp), atk(atk) {
			cout << name << " is online\n";
		}
		~Player() { cout << name << " is offline\n"; }
		void attack(IMonster* monster);
		void getDamage(float dmg);
		string& getName();
		
	};
}

namespace AbstractFactoryMethod {
	enum PlayerClass {
		Warrior,
		Archer,
		Magician
	};

	class IArmor;

	class Player {
	private:
		string name = "";
		float hp = 100;
		float atk = 10;
		PlayerClass playerClass;
		IArmor* wearingArmor = nullptr;
	public:
		Player(const string& name, float hp, float atk, PlayerClass playerClass)
			: name(name), hp(hp), atk(atk), playerClass(playerClass) {
			cout << name << " is online\n";
		}
		~Player() { cout << name << " is offline\n"; }
		void suitArmor(IArmor* armor);
		string& getName() { return this->name; }
		PlayerClass getPlayerClass() { return this->playerClass; }
		IArmor* getWearingArmor() { return this->wearingArmor; }
	};
}

namespace Builder {
	class Potion;

	class Player {
	public:
		string name = "";
		float hp = 100;
		float atk = 8;
		float speed = 100;
		float def = 3;

	public:
		Player(const string& name, float hp, float atk, float speed, float def)
			: name(name), hp(hp), atk(atk), speed(speed), def(def){
			cout << name << " is online\n";
		}
		~Player() {
			cout << name << " is offline\n";
		}

		void drinkPotion(Potion* potion);

		void showPlayerStatus();
	};
}