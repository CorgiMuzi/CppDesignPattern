#include "Singleton.h"

namespace Singleton {
	PlayerDB* PlayerDB::instance = nullptr;

	PlayerDB* PlayerDB::GetInstance() {
		if (instance == nullptr) {
			cout << "Game operated.\n";
			instance = new PlayerDB();
		}

		return instance;
	}

	void PlayerDB::SavePlayer(Player* player) {
		instance->player = new Player(*player);
		cout << "\n[-] Save completed!!\n";
	}

	Player* PlayerDB::getSavedPlayer() {
		if (instance->player == nullptr) {
			instance->player = new Player();
		}

		cout << "\n[!] " << instance->player->getPlayerName() << " has singed in.\n";
		return new Player(*instance->player);
	}

	void Shop::buyHpPotion(Player* player) {
		cout << "\n" << player->getPlayerName() << " bought one HP potion.\n";
		if (player->payGold(this->healthPotionCost)) {
			cout << "-" << this->healthPotionCost << "G\n";
			player->hpPotionAmount++;
		}
	}

	void Shop::buyBuffPotion(Player* player) {
		cout << "\n" << player->getPlayerName() << " bought one Buff potion.\n";
		if (player->payGold(this->buffPotionCost)) {
			cout << "-" << this->buffPotionCost << "G\n";
			player->buffPotionAmount++;
		}
	}

	Player::Player() {
		this->name = "GUEST";
		this->gold = 100;

		cout << "\n[!] GUEST player has created.\n";
	}

	Player::Player(const string& name, int gold) : name(name), gold(gold) {
		cout << "\n[!] " << this->name << " player has created.\n";
	}

	void Player::showPlayerInfo() {
		cout << "\n==== " << this->name << " ====\n";
		cout << "GOLD: " << this->gold << "G\n";
		cout << "HP POTION: " << this->hpPotionAmount << "\n";
		cout << "BUFF POTION: " << this->buffPotionAmount << "\n";
		cout << string(this->name.length() + 10, '=') << "\n";
	}

	bool Player::payGold(int cost) {
		if (this->gold >= cost) {
			this->gold -= cost;
			return true;
		}
		else {
			cout << "Not enough gold.\n";
			return false;
		}
	}

	void Player::gainGold(int gold) {
		this->gold += gold;
	}
}