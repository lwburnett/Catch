// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Components/ActorComponent.h"
#include "BehaviorBase.h"
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
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> _projectileBlueprint;


	TArray<TUniquePtr<BehaviorBase>> _behaviors;

	TSubclassOf<AProjectile> FindClass(TCHAR* blueprintPath) const;

	//static FText* _blueprintPath = TEXT("\\GameMode\\Blueprints\\PrototypeProjectile");
};
