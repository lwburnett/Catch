// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeSpawnerComponent.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "PrototypeBehavior.h"

// Sets default values for this component's properties
UPrototypeSpawnerComponent::UPrototypeSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	_projectileBlueprint = FindClass(TEXT_PASTE("Blueprint'/Game/GameMode/Blueprints/PrototypeProjectile.PrototypeProjectile_C'"));
}


// Called when the game starts
void UPrototypeSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	//TODO: figure out adding and deleting strategy for behaviors (maybe use a behavior provider type pattern)
	_behaviors.Emplace(new PrototypeBehavior(10));
}


// Called every frame
void UPrototypeSpawnerComponent::TickComponent(
	const float deltaTime, 
	const ELevelTick tickType, 
	FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	for (const auto& behavior : _behaviors)
	{
		behavior->Tick(deltaTime);

		if(behavior->ShouldSpawn())
		{
			if (!ensure(_projectileBlueprint))
			{
				UE_LOG(LogTemp, Warning, TEXT("No projectile blueprint found for spawner!"));
				continue;
			}

			const auto world = GetWorld();
			const auto projectileBp = _projectileBlueprint;

			behavior->Spawn(
				[world, projectileBp](const FVector v)
				{
					return world->SpawnActor<AProjectile>(
						projectileBp, 
						v, 
						FRotator(0.0, 0.0, 0.0));
				});
		}
	}
}

TSubclassOf<AProjectile> UPrototypeSpawnerComponent::FindClass(TCHAR* blueprintPath) const
{
	if (const auto result = FindObject<UClass>(ANY_PACKAGE, blueprintPath))
		return *static_cast<TSubclassOf<AProjectile>>(result);

	return nullptr;
}
