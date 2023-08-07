#include "Builder.h"

int main() {
	PotionBrewer* brewer = new PotionBrewer();
	PotionBuilder* builder = new PotionBuilder();

	Player* player = new Player("Corgi", 100, 15, 10, 8);

	brewer->set_builder(builder);

	cout << "* Brewing <Full buff> potion\n";
	brewer->brewingFullPotion();

	Potion* potion = builder->getPotion();
	potion->potionStatus();

	delete potion;

	cout << "* Brewing <HP buff> potion\n";
	brewer->brewingHpPotion();

	potion = builder->getPotion();
	potion->potionStatus();
	
	cout << "+ Before drinking potion +\n";
	player->showPlayerStatus();
	player->drinkPotion(potion);
	cout << "+ After drinking potion +\n";
	player->showPlayerStatus();
	delete potion;
	delete player;
	delete builder;
	delete brewer;
}