// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorBase.h"

/**
 * 
 */
class CATCH_API PrototypeBehavior : public BehaviorBase
{
public:
	explicit PrototypeBehavior(int numToSpawn);

	~PrototypeBehavior() = default;

	bool ShouldSpawn(float timeSeconds, float lastSpawnTime) override;

	FVector GetNextLaunchVector() override;

private:
	float _interval;
};
