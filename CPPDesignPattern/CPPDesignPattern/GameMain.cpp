#include "Prototype.h"

int main() {
	ZombieSpawner* zombieSpawner = new ZombieSpawner();

	IMonster* zombie = zombieSpawner->spawnMonster(100, 15);
	zombie->setSpeed(41);

	vector<IMonster*> zombies;
	zombies.push_back(zombie);

	for (int unit = 0; unit < 4; ++unit) {
		zombies.push_back(zombieSpawner->spawnMonster(*zombie));
	}

	cout << "\n";

	for (vector<IMonster*>::size_type unit = 0; unit < zombies.size(); ++unit) {
		if (unit == 0) cout << "[prototype]\n";
		else cout << "[clone]\n";
		zombies[unit]->showStatus();
	}
}