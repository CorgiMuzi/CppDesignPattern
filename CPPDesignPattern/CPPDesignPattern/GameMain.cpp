#include "AbstractFactoryMethod.h"

int main() {
	Player* player = new Player("Corgi", 150, 13, Magician);

	Forge* forge = nullptr;
	switch (player->getPlayerClass()) {
	case Warrior:
		forge = new WarriorForge();
		break;
	case Archer:
		forge = new ArcherForge();
		break;
	case Magician:
		forge = new MagicianForge();
		break;
	default:
		forge = new WarriorForge();
		break;
	}

	IArmor* armor = forge->reforgingArmor("Dragon Leather",15 ,97);

	cout << armor->getDefStatInfo() << armor->getDurabilityInfo();
	player->suitArmor(armor);

	delete armor;
	delete forge;
	delete player;
}