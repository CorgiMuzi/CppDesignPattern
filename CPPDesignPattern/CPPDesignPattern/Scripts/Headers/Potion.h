#pragma once
#include "Buff.h"
#include <vector>

using std::vector;

namespace Builder {
	class Potion {
	public:
		vector<IBuff*> buffVec;
		void potionStatus();
	};

	class IPotionBuilder {
	public:
		virtual ~IPotionBuilder() {};
		virtual void addHpBuff() const = 0;
		virtual void addAtkBuff() const = 0;
		virtual void addSpeedBuff() const = 0;
		virtual void addDefBuff() const = 0;
	};

	class PotionBuilder : IPotionBuilder {
	private:
		Potion* potion;

	public:
		PotionBuilder() {
			this->rebrewPotion();
		}

		~PotionBuilder() {
			delete potion;
		}

		void rebrewPotion() {
			this->potion = new Potion();
		}

		void addHpBuff() const override;
		void addAtkBuff() const override;
		void addSpeedBuff() const override;
		void addDefBuff() const override;

		Potion* getPotion() {
			Potion* result = this->potion;
			this->rebrewPotion();
			return result;
		}
	};

	class PotionBrewer {
	private:
		PotionBuilder* potionBuilder;

	public:
		void set_builder(PotionBuilder* pb) {
			this->potionBuilder = pb;
		}

		void brewingHpPotion() {
			this->potionBuilder->addHpBuff();
		}

		void brewingAtkPotion() {
			this->potionBuilder->addAtkBuff();
		}

		void brewingDefPotion() {
			this->potionBuilder->addDefBuff();
		}

		void brewingSpeedPotion() {
			this->potionBuilder->addSpeedBuff();
		}

		void brewingFullPotion() {
			this->potionBuilder->addHpBuff();
			this->potionBuilder->addAtkBuff();
			this->potionBuilder->addDefBuff();
			this->potionBuilder->addSpeedBuff();
		}
	};
}