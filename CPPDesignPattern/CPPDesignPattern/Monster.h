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

namespace Prototype {
	class IMonster {
	protected:
		float hp = 100.0f;
		float atk = 5.0f;
		float speed = 15.0f;

	public:
		IMonster(float hp, float atk) : hp(hp), atk(atk) {}
		~IMonster() {};
		virtual IMonster* clone() = 0;
		virtual void setSpeed(float speed) { this->speed = speed; }
		virtual void showStatus() {
			cout << "Empty monster\n";
		}
	};

	class Zombie : public IMonster {
	public:
		Zombie(float hp, float atk)
			: IMonster(hp, atk) { cout << "Zombie created\n"; }
		~Zombie() { cout << "Zombie object has destroyed\n"; }

		IMonster* clone() override {
			return new Zombie(*this);
		}

		void setSpeed(float speed) { this->speed = speed; }

		void showStatus() override;
	};
}