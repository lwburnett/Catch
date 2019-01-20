// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeSpawnerComponent.h"
#include "Engine/World.h"
#include "Projectile.h"

// Sets default values for this component's properties
UPrototypeSpawnerComponent::UPrototypeSpawnerComponent() :
		_lastSpawnTime(0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPrototypeSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	_lastSpawnTime = GetWorld()->GetTimeSeconds();
}


// Called every frame
void UPrototypeSpawnerComponent::TickComponent(
	const float deltaTime, 
	const ELevelTick tickType, 
	FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (GetWorld()->GetTimeSeconds() - _lastSpawnTime > 2)
		Spawn();
}

void UPrototypeSpawnerComponent::Spawn()
{
	_lastSpawnTime = GetWorld()->GetTimeSeconds();

	const auto projectile = GetWorld()->SpawnActor<AProjectile>(
		_projectileBlueprint,
		FVector(0,0,2200),
		FRotator(0,0,0));

	const FVector launch(1000, 0, 0);

	projectile->Launch(launch);
}
