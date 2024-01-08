#include "Headers/Prototype.h"

namespace Prototype {
	void Zombie::showStatus() {
		cout << "=== Zombie status ===\n";
		cout << "HP: " << this->hp << "\n";
		cout << "ATK: " << this->atk << "\n";
		cout << "SPD: " << this->speed << "\n";
		cout << "MEM ADDR: " << this << "\n";
		cout << "=====================\n\n";
	}

	IMonster* ZombieSpawner::spawnMonster(IMonster& monster) {
		return monster.clone();
	}

	IMonster* ZombieSpawner::spawnMonster(float hp, float atk) {
		return new Zombie(hp, atk);
	}
}