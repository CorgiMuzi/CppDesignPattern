#include "Headers/Adapter.h"

int main() {
	Player* player = new Player("Corgi");

	ClubMinion* clubMinion = new ClubMinion("Minion");
	ClubCreep* clubCreep = new ClubCreep("Creep");
	MinionAdapter* adapteedClubCreep = new MinionAdapter((ICreep*)clubCreep); 

	cout << "\n";
	player->FireBlade((IMinion*)clubMinion);
	cout << "==============================\n";
	player->FireBlade(adapteedClubCreep);
	cout << "\n";
	
	delete(clubCreep);
	delete(clubMinion);
	delete(player);
	
	return 0;
}