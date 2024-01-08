#pragma once
#include "IOBase.h"

namespace AbstractFactoryMethod
{
	enum PlayerClass;

	class IArmor {
	protected:
		PlayerClass armorClass;
		string name;
		float defStat = 0;
		float durability = 100.0f;

	public:
		IArmor(const PlayerClass& armorClass, const string& name, float defStat, float durability)
			: armorClass(armorClass), name(name), defStat(defStat), durability(durability) {
		}
		~IArmor() { cout << this->name << " has destroyed\n"; }
		virtual string getDurabilityInfo() = 0;
		virtual string getDefStatInfo() = 0;
		PlayerClass getArmorClass() { return this->armorClass; }
		string getName() { return this->name; }
	};

	class WarriorArmor : public IArmor {
	public:
		WarriorArmor(const string& name, float defStat, float durability = 100)
			: IArmor(Warrior, name, defStat, durability) {
		}
		string getDurabilityInfo();
		string getDefStatInfo();
	};

	class ArcherArmor : public IArmor {
	public:
		ArcherArmor(const string& name, float defStat, float durability = 100)
			: IArmor(Archer, name, defStat, durability) {
		}
		string getDurabilityInfo();
		string getDefStatInfo();
	};

	class MagicianArmor : public IArmor {
	public:
		MagicianArmor(const string& name, float defStat, float durability = 100)
			: IArmor(Magician, name, defStat, durability) {
		}
		string getDurabilityInfo();
		string getDefStatInfo();
	};
}