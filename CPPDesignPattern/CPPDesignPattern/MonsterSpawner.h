#pragma once
#include "IOBase.h"
#include "Monster.h"

namespace FactoryMethod {
	class MonsterSpawner {
	private:
	public:
		MonsterSpawner() {}
		virtual ~MonsterSpawner() = 0;
		virtual IMonster* SpawnMonster(const string& name, float hp, float atk) = 0;
	};

	class GoblinSpawner : public MonsterSpawner {
	private:
	public:
		~GoblinSpawner() override;
		IMonster* SpawnMonster(const string& name, float hp, float atk);
	};

	class SkeletonSpawner : public MonsterSpawner {
	private:
	public:
		~SkeletonSpawner() override;
		IMonster* SpawnMonster(const string& name, float hp, float atk);
	};
}