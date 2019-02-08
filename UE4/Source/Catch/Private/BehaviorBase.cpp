// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorBase.h"

BehaviorBase::BehaviorBase(const int numToSpawn): 
		_activationTime(0), 
		_activated(false), 
		_numSpawned(0)
{
	_numToSpawn = numToSpawn;
}

void BehaviorBase::Activate(const float timeSeconds)
{
	_activationTime = timeSeconds;
	_activated = true;
}

bool BehaviorBase::ShouldSpawn(float timeSeconds, float lastSpawnTime)
{
	return _activated && _numSpawned < _numToSpawn;
}

void BehaviorBase::NotifySpawned()
{
	_numSpawned++;
}

float BehaviorBase::GetActivationTime() const
{
	return _activationTime;
}
