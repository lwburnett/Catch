// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CATCH_API BehaviorBase
{
public:
	explicit BehaviorBase(int numToSpawn);

	virtual ~BehaviorBase() = default;

	virtual void Activate(float timeSeconds);

	virtual bool ShouldSpawn(float timeSeconds, float lastSpawnTime = 0);

	virtual FVector GetNextLaunchVector() = 0;

	void NotifySpawned();

protected:
	float GetActivationTime() const;

private:
	float _activationTime;
	bool _activated;
	int _numSpawned;
	int _numToSpawn;
};
