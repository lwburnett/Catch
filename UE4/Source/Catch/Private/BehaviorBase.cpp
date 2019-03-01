// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorBase.h"

BehaviorBase::BehaviorBase(const int numToSpawn):
		_elapsedTimeSeconds(0.0),
		_numSpawned(0), 
		_lastSpawnTime(0)
{
	_numToSpawn = numToSpawn;
}

void BehaviorBase::Tick(const float timeSeconds)
{
	_elapsedTimeSeconds += timeSeconds;
}

bool BehaviorBase::ShouldSpawn()
{
	//UE_LOG(LogTemp, Warning, TEXT("%d, %d"), _numSpawned, _numToSpawn);
	return _numSpawned < _numToSpawn;
}

void BehaviorBase::Spawn(
	const TFunction<AProjectile*(FVector)>& spawnFunc)
{
	_numSpawned++;
	_lastSpawnTime = _elapsedTimeSeconds;

	//TODO: how to deal with spawn mins and maxes?
	const auto projectile = spawnFunc(
		GetNextSpawnVector(-700, 700, 2200));

	projectile->Launch(GetNextLaunchVector());
}

float BehaviorBase::GetElapsedTimeSeconds() const
{
	return _elapsedTimeSeconds;
}

float BehaviorBase::GetLastSpawnTimeSeconds() const
{
	return _lastSpawnTime;
}

// ReSharper disable CppParameterNeverUsed
FVector BehaviorBase::GetNextSpawnVector(float spawnXMin, float spawnXMax, float height)
// ReSharper restore CppParameterNeverUsed
{
	return {0, 0, height};
}

FVector BehaviorBase::GetNextLaunchVector()
{
	return {0.0, 0.0, 0.0};
}
