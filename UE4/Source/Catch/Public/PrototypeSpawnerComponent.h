// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PrototypeSpawnerComponent.generated.h"


class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CATCH_API UPrototypeSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPrototypeSpawnerComponent();

protected:
	// Called when the game starts
	void BeginPlay() override;

public:	
	// Called every frame
	void TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;


private:
	float _lastSpawnTime;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> _projectileBlueprint;

	// FIRST-PASS PROTOTYPE
	void Spawn();
};
