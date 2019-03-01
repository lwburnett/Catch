// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"

/**
 * 
 */
class CATCH_API BehaviorBase
{
public:
	explicit BehaviorBase(int numToSpawn);

	virtual ~BehaviorBase() = default;

	virtual void Tick(float timeSeconds);

	virtual bool ShouldSpawn();

	void Spawn(
		const TFunction<AProjectile*(FVector)>& spawnFunc);

protected:
	float GetElapsedTimeSeconds() const;
	float GetLastSpawnTimeSeconds() const;

	virtual FVector GetNextSpawnVector(float spawnXMin, float spawnXMax, float height);
	virtual FVector GetNextLaunchVector();

private:
	float _elapsedTimeSeconds;
	int _numSpawned;
	int _numToSpawn;
	float _lastSpawnTime;
};
