#include "Headers/Adapter.h"

namespace Adapter
{
	void ClubMinion::BeDamaged(float _dmg) {
		cout << this->GetMinionName() << " get " << _dmg << " damage!\n";
		this->hp -= _dmg;
	}

	void ClubCreep::BeDamaged(float _dmg) {
		cout << this->GetCreepName() << " get " << _dmg << " damage!\n";
		this->hp -= _dmg;
	}

	void MinionAdapter::BeDamaged(float _dmg) {
		cout << this->GetMinionName() << " get " << _dmg << " damage!\n";
		this->hp -= _dmg;
	}
	
	void Player::FireBlade(IMinion* minion) {
		cout << this->GetPlayerName() << " used Fire blade!\n";
		minion->BeDamaged(this->atk);
	}
}
