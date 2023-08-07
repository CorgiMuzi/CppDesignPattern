#pragma once

namespace Builder {
	class Player;
	class IBuff {
	public:
		virtual void explainBuff() = 0;
		virtual void buffEffect(Player* player) = 0;
	};

	class HealthBuff : public IBuff {
		void explainBuff() override;
		void buffEffect(Player* player) override;
	};

	class SpeedBuff : public IBuff {
		void explainBuff() override;
		void buffEffect(Player* player) override;
	};

	class AtkBuff : public IBuff {
		void explainBuff() override;
		void buffEffect(Player* player) override;
	};

	class DefBuff : public IBuff {
		void explainBuff() override;
		void buffEffect(Player* player) override;
	};
}
