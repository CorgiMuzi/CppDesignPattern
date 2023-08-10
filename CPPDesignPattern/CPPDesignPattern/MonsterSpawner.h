#pragma once
#include "IOBase.h"
#include "Monster.h"

namespace FactoryMethod {
	class IMonsterSpawner {
	private:
	public:
		IMonsterSpawner() {}
		virtual ~IMonsterSpawner() = 0;
		virtual IMonster* spawnMonster(const string& name, float hp, float atk) = 0;
	};

	class GoblinSpawner : public IMonsterSpawner {
	private:
	public:
		~GoblinSpawner() override;
		IMonster* spawnMonster(const string& name, float hp, float atk);
	};

	class SkeletonSpawner : public IMonsterSpawner {
	private:
	public:
		~SkeletonSpawner() override;
		IMonster* spawnMonster(const string& name, float hp, float atk);
	};
}

namespace Prototype {
	class IMonsterSpawner {
	protected:
		IMonsterSpawner() {}
		~IMonsterSpawner() {};
	public:
		virtual IMonster* spawnMonster(IMonster&) = 0;
	};

	class ZombieSpawner : public IMonsterSpawner{
	private:
		~ZombieSpawner() { cout << "Zombie spawner has destroyed\n"; }
	public:
		IMonster* spawnMonster(float hp, float atk);
		IMonster* spawnMonster(IMonster&) override;
		void zombieBehaviour() {}
	};
}