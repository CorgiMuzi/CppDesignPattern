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

namespace Singleton {
	class Player {
	private:
		string name = "";
		int gold = 100;

	public:
		int hpPotionAmount = 0;
		int buffPotionAmount = 0;

	public:
		Player();
		Player(const string& name, int gold);
		~Player() { cout << "\n[!] " << this->name << " has signed out.\n"; }

		void showPlayerInfo();
		bool payGold(int cost);
		void gainGold(int gold);
		string getPlayerName() { return this->name; }
	};
}

namespace Adpater
{
	class IMinion;
	
	class Player {
	private:
		string name;
		float atk;
		float hp;

	public:
		Player() : name("Guest"), atk(1.0f), hp(100.0f) {}
		Player(string _name, float _atk, float _hp) : name(_name), atk(_atk), hp(_hp) {}
		string GetPlayerName() { return name; }
		void FireBlade(IMinion minion);
	};
}