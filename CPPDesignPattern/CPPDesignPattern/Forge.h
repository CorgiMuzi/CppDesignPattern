#pragma once
#include "Armor.h"

namespace AbstractFactoryMethod {
	class Forge {
	public:
		virtual IArmor* reforgingArmor(const string& name, float defStat, float durability = 100) = 0;
	};

	class WarriorForge : public Forge {
	public:
		IArmor* reforgingArmor(const string& name, float defStat, float durability = 100);
	};

	class ArcherForge : public Forge {
	public:
		IArmor* reforgingArmor(const string& name, float defStat, float durability = 100);
	};

	class MagicianForge : public Forge {
	public:
		IArmor* reforgingArmor(const string& name, float defStat, float durability = 100);
	};
}