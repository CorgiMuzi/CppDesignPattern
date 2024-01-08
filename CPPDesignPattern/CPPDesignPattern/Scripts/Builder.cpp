#include "Headers/Builder.h"

namespace Builder {
	void HealthBuff::explainBuff() {
		cout << "This potion contains <Health buff>\n";
	}

	void HealthBuff::buffEffect(Player* player) {
		player->hp += 50;
	}

	void SpeedBuff::explainBuff() {
		cout << "This potion contains <Speed buff>\n";
	}

	void SpeedBuff::buffEffect(Player* player) {
		player->speed += 5;
	}

	void AtkBuff::explainBuff() {
		cout << "This potion contains <Atk buff>\n";
	}

	void AtkBuff::buffEffect(Player* player) {
		player->atk += 30;
	}

	void DefBuff::explainBuff() {
		cout << "This potion contains <Def buff>\n";
	}

	void DefBuff::buffEffect(Player* player) {
		player->def += 10;
	}

	void Potion::potionStatus() {
		cout << "======= Potion Buff =======\n";
		for (IBuff* buff : buffVec) {
			buff->explainBuff();
		}
		cout << "===========================\n\n";
	}

	void PotionBuilder::addHpBuff() const {
		this->potion->buffVec.push_back(new HealthBuff());
	}

	void PotionBuilder::addAtkBuff() const {
		this->potion->buffVec.push_back(new AtkBuff());
	}

	void PotionBuilder::addDefBuff() const {
		this->potion->buffVec.push_back(new DefBuff());
	}
	 
	void PotionBuilder::addSpeedBuff() const {
		this->potion->buffVec.push_back(new SpeedBuff());
	}

	void Player::drinkPotion(Potion* potion) {
		for (IBuff* buff : potion->buffVec) {
			buff->buffEffect(this);
		}
	}
	
	void Player::showPlayerStatus() {
		cout << "====== Player Status ======\n";
		cout << "HP: " << hp << "\n" << "ATK: " << atk << "\n";
		cout << "DEF: " << def << "\n" << "SPD: " << speed << "\n";
		cout << "===========================\n\n";
	}
}