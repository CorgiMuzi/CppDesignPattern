#pragma once
#include "IOBase.h"

namespace FactoryMethod {
	class Player;

	class IMonster {
	protected:
		string name = "";
		float hp = 100;
		float atk = 10;

	public:
		virtual ~IMonster() {};
		virtual void attack(Player* player) = 0;
		virtual void getDamage(float dmg) = 0;
		virtual string& getName() = 0;

		IMonster(const string& name, float hp, float atk)
			: name(name), hp(hp), atk(atk) {}
	};

	class Goblin : public IMonster {
	public:
		Goblin(const string& name, float hp, float atk) : IMonster(name, hp, atk) {}
		~Goblin() override;
		void attack(Player* player) override;
		void getDamage(float dmg) override;
		string& getName() override { return this->name; }
	};

	class Skeleton : public IMonster {
	public:
		Skeleton(const string& name, float hp, float atk) : IMonster(name, hp, atk) {}
		~Skeleton() override;
		void attack(Player* player) override;
		void getDamage(float dmg) override;
		string& getName() override { return this->name; }
	};
};