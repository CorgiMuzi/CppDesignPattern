#pragma once
#include "Player.h"

namespace Singleton {
	class Player;

	class Shop {
	public:
		int healthPotionCost = 0;
		int buffPotionCost = 0;

	public:
		Shop(int healthPotionCost, int buffPotionCost)
			: healthPotionCost(healthPotionCost), buffPotionCost(buffPotionCost) {}
		~Shop() {}

		void buyHpPotion(Player* player);
		void buyBuffPotion(Player* player);
	};
}