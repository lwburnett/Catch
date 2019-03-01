// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeBehavior.h"

PrototypeBehavior::PrototypeBehavior(const int numToSpawn): BehaviorBase(numToSpawn), 
		_interval(2.0)
{
	UE_LOG(LogTemp, Warning, TEXT("RASPBERRY"));
}

bool PrototypeBehavior::ShouldSpawn()
{
	const auto baseShouldSpawn = BehaviorBase::ShouldSpawn();

	const auto shouldSpawn = GetElapsedTimeSeconds() - GetLastSpawnTimeSeconds() > _interval;

	return baseShouldSpawn && shouldSpawn;
}

FVector PrototypeBehavior::GetNextSpawnVector(const float spawnXMin, const float spawnXMax, const float height)
{
	return { FMath::FRandRange(spawnXMin, spawnXMax), 0, height };
}

//TODO: Add in logic (mins and maxes??)
FVector PrototypeBehavior::GetNextLaunchVector()
{
	return {1000, 0, 0};
}
