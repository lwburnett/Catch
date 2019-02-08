// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeSpawnerComponent.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "PrototypeBehavior.h"

// Sets default values for this component's properties
UPrototypeSpawnerComponent::UPrototypeSpawnerComponent() :
		_lastSpawnTime(0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	_behavior.Reset(new PrototypeBehavior(10));
}

UPrototypeSpawnerComponent::~UPrototypeSpawnerComponent()
{
	_behavior.Release();
}


// Called when the game starts
void UPrototypeSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	_lastSpawnTime = GetWorld()->GetTimeSeconds();
	_behavior->Activate(_lastSpawnTime);
}


// Called every frame
void UPrototypeSpawnerComponent::TickComponent(
	const float deltaTime, 
	const ELevelTick tickType, 
	FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	const auto now = GetWorld()->GetTimeSeconds();

	if (_behavior->ShouldSpawn(now, _lastSpawnTime))
	{
		Spawn(_behavior->GetNextLaunchVector());
	}
}

void UPrototypeSpawnerComponent::Spawn(const FVector initialVelocity)
{
	if(!ensure(_projectileBlueprint))
	{
		UE_LOG(LogTemp, Warning, TEXT("No projectile blueprint found for spawner!"));
		return;
	}

	_lastSpawnTime = GetWorld()->GetTimeSeconds();

	const auto projectile = GetWorld()->SpawnActor<AProjectile>(
		_projectileBlueprint,
		FVector(0,0,2200),
		FRotator(0,0,0));

	projectile->Launch(initialVelocity);
	_behavior->NotifySpawned();
}
