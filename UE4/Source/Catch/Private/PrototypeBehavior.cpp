// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeBehavior.h"

PrototypeBehavior::PrototypeBehavior(const int numToSpawn): BehaviorBase(numToSpawn), 
		_interval(2.0)
{
}

bool PrototypeBehavior::ShouldSpawn(const float timeSeconds, const float lastSpawnTime)
{
	const auto baseShouldSpawn = BehaviorBase::ShouldSpawn(timeSeconds);

	const auto shouldSpawn = timeSeconds - lastSpawnTime;

	return shouldSpawn >= _interval && baseShouldSpawn;
}

FVector PrototypeBehavior::GetNextLaunchVector()
{
	return FVector(1000, 0, 0);
}
