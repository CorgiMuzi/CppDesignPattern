#include "Singleton.h"

int main() {
	PlayerDB* playerDB = PlayerDB::GetInstance();
	Player* player = playerDB->getSavedPlayer();
	Shop* shop = new Shop(15, 30);

	player->showPlayerInfo();

	cout << "\n[~] Creating new player...\n";

	player = new Player("Corgi", 150);
	player->showPlayerInfo();
	PlayerDB::SavePlayer(player);

	delete player;

	player = playerDB->getSavedPlayer();
	player->showPlayerInfo();

	shop->buyHpPotion(player);

	player->showPlayerInfo();

	PlayerDB::SavePlayer(player);

	delete player;

	cout << "\n[*] Refer new DB and save player info in it.\n";

	PlayerDB* newPlayerDB = PlayerDB::GetInstance();

	player = newPlayerDB->getSavedPlayer();
	player->showPlayerInfo();

	shop->buyBuffPotion(player);
	player->showPlayerInfo();
	PlayerDB::SavePlayer(player);

	delete player;

	cout << "\n[*] Now, try to get player info from original DB\n";

	player = playerDB->getSavedPlayer();
	player->showPlayerInfo();

	delete playerDB;
	delete player;
}