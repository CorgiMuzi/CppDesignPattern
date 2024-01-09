#pragma once
#include "IOBase.h"

namespace FactoryMethod
{
	class Player;

	class IMonster {
	protected:
		string name = "";
		float hp = 100;
		float atk = 10;

	public:
		virtual ~IMonster() = default;
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

namespace Prototype
{
	class IMonster {
	protected:
		float hp = 100.0f;
		float atk = 5.0f;
		float speed = 15.0f;

	public:
		IMonster(float hp, float atk) : hp(hp), atk(atk) {}

	protected:
		~IMonster() = default;

	public:
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

	protected:
		~Zombie() { cout << "Zombie object has destroyed\n"; }

	public:
		IMonster* clone() override {
			return new Zombie(*this);
		}

		void setSpeed(float speed) override { this->speed = speed; }

		void showStatus() override;
	};
}

namespace Adapter
{
	class IMinion {
	protected:
		virtual ~IMinion() = default;
		string name;
		float atk;
		float hp;

	public:
		IMinion(string _name, float _atk, float _hp) : name(_name), atk(_atk), hp(_hp) {}
		virtual void BeDamaged(float _dmg) {};
		string& GetMinionName() { return name; }
	};

	class ClubMinion : IMinion {
	private:
		string clubName;

	public:
		ClubMinion(string _name = "Club Minion", float _atk = 0.3f, float _hp = 10.0f, string _clubName = "Wooden Club") : IMinion(_name, _atk, _hp), clubName(_clubName) {
			cout << name << " has created\n";
		}
		~ClubMinion() override { cout << name << " is destroyed after game ends\n"; }
		void BeDamaged(float _dmg) override;
	};

	class ICreep {
	protected:
		virtual ~ICreep() = default;
		string name;
		float atk;
		float hp;

	public:
		ICreep(string _name, float _atk, float _hp) : name(_name), atk(_atk), hp(_hp) {}
		string& GetCreepName() { return name; }
		float& GetCreepAtk() { return atk; }
		float& GetCreepHp() { return hp; }
		virtual void BeDamaged(float _dmg) {};
	};

	class ClubCreep : ICreep {
	private:
		string clubName;

	public:
		ClubCreep(string _name = "Club Creep", float _atk = 0.4f, float _hp = 10.0f, string _clubName = "Wooden Club") : ICreep(_name, _atk, _hp), clubName(_clubName) {
			cout << name << " has created\n";
		}
		~ClubCreep() override { cout << name << " is destroyed after game ends\n"; }
		void BeDamaged(float _dmg) override;
	};

	class MinionAdapter : public IMinion {
	private:
		ICreep* creep;

	public:
		MinionAdapter(ICreep* _creep) : IMinion(_creep->GetCreepName(), _creep->GetCreepAtk(), _creep->GetCreepHp()), creep(_creep) {
			cout << creep->GetCreepName() << " adapted to Minion world!\n";
		}
		void BeDamaged(float _dmg) override;
	};
};