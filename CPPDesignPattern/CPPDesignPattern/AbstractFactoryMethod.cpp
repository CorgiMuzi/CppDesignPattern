#include "AbstractFactoryMethod.h"

namespace AbstractFactoryMethod {
	string WarriorArmor::getDurabilityInfo() {
		cout << "Checking for warrior armor's durability\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->durability;
		return this->name + " has " + ss.str()  + " durability left\n";
	}

	string WarriorArmor::getDefStatInfo() {
		cout << "Checking for warrior armor's defense stat\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->defStat;
		return this->name + " has " + ss.str() + " defense stat\n";
	}

	string ArcherArmor::getDurabilityInfo() {
		cout << "Analyzing for archer armor's durability\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->durability;
		return this->name + " has " + ss.str() + " durability left\n";
	}

	string ArcherArmor::getDefStatInfo() {
		cout << "Analyzing for archer armor's defense stat\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->defStat;
		return this->name + " has " + ss.str() + " defense stat\n";
	}

	string MagicianArmor::getDurabilityInfo() {
		cout << "Drawing magician armor's durability on the air\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->durability;
		return this->name + " has " + ss.str() + " durability left\n";
	}

	string MagicianArmor::getDefStatInfo() {
		cout << "Drawing magician armor's defense stat on the air\n";
		stringstream ss;
		ss << fixed << setprecision(1) << this->defStat;
		return this->name + " has " + ss.str() + " defense stat\n";
	}

	void Player::suitArmor(IArmor* armor) {
		if (this->wearingArmor != nullptr) {
			cout << this->name << " is already wearing " << this->wearingArmor->getName() << "\n";
			return;
		}

		if (armor->getArmorClass() == this->playerClass) {
			this->wearingArmor = armor;
			cout << this->name << " is wearing " << this->wearingArmor->getName() << "\n";
			return;
		}

		cout << armor->getName() << " is not suitable for " << this->name << "'s class\n";
		cout << "Try other class' armor\n";
	}

	IArmor* WarriorForge::reforgingArmor(const string& name, float defStat, float durability) {
		return new WarriorArmor(name, defStat, durability);
	}
	
	IArmor* ArcherForge::reforgingArmor(const string& name, float defStat, float durability) {
		return new ArcherArmor(name, defStat, durability);
	}

	IArmor* MagicianForge::reforgingArmor(const string& name, float defStat, float durability) {
		return new MagicianArmor(name, defStat, durability);
	}
}