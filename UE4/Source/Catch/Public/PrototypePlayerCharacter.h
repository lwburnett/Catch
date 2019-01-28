// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PrototypePlayerCharacter.generated.h"


struct FHitResult;
class UBoxComponent;

/**
 * 
 */
UCLASS()
class CATCH_API APrototypePlayerCharacter : public APaperCharacter
{
	GENERATED_BODY()

	// SOME BULLSHIT TO GET AN ACHARACTER TO USE ANOTHER MOVEMENT COMPONENT WTF
	APrototypePlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

private:
	//UBasicMovementBase* _movementComponent{};

	UPROPERTY(VisibleAnywhere, category = "Components")
	UBoxComponent* _boxComponent;

	UFUNCTION(BlueprintCallable)
	void OnCatch(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex,
		bool bFromSweep,
		const FHitResult &sweepResult);
};
