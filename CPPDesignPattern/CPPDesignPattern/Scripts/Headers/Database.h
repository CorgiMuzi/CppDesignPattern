#pragma once
#include "IOBase.h"
#include "Player.h"

namespace Singleton {
	class Player;

	class PlayerDB {
	protected:
		Player* player = nullptr;
		static PlayerDB* instance;
	
	protected:
		PlayerDB() {}

	public:
		~PlayerDB() {}
		static PlayerDB* GetInstance();
		static void SavePlayer(Player* player);
		Player* getSavedPlayer();
	};
}