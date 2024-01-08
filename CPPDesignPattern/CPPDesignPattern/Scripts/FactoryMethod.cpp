#include "Headers/FactoryMethod.h"

namespace FactoryMethod {
	IMonsterSpawner::~IMonsterSpawner() {
		cout << " get destroyed\n";
	}

	GoblinSpawner::~GoblinSpawner() {
		cout << "Goblin spawner";
	}

	IMonster* GoblinSpawner::spawnMonster(const string& name, float hp, float atk) {
		return new Goblin(name, hp, atk);
	}

	SkeletonSpawner::~SkeletonSpawner() {
		cout << "Skeleton spawner";
	}

	IMonster* SkeletonSpawner::spawnMonster(const string& name, float hp, float atk) {
		return new Skeleton(name, hp, atk);
	}

	Goblin::~Goblin() {
		cout << this->name << " has vanished as dust into the air\n";
	}

	Skeleton::~Skeleton() {
		cout << this->name << " has returned to the earth\n";
	}

	void Goblin::attack(Player* player) {
		cout << this->name << " is attacking " << player->getName() << " using [wooden club]\n";
		player->getDamage(this->atk);
	}

	void Goblin::getDamage(float dmg) {
		this->hp -= dmg;
		cout << "Arrrrrrggggg!!!!\n";
	}

	void Skeleton::attack(Player* player) {
		cout << this->name << " is attacking " << player->getName() << " using [bone arrow]\n";
		player->getDamage(this->atk);
	}

	void Skeleton::getDamage(float dmg) {
		this->hp -= dmg;
		cout << "Cracked!!\n";
	}

	void Player::attack(IMonster* monster) {
		cout << this->name << " is attacking " << monster->getName() << "\n";
		monster->getDamage(this->atk);
	}

	void Player::getDamage(float dmg) {
		this->hp -= dmg;
		cout << this->name << " took " << dmg << " damage\n";
	}

	string& Player::getName() {
		return this->name;
	}
}