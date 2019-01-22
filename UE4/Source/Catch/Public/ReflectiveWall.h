// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "ReflectiveWall.generated.h"

UCLASS()
class CATCH_API AReflectiveWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReflectiveWall();
	
protected:
	void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, category = "Components")
	UCapsuleComponent* _capsuleComponent;

	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex,
		bool bFromSweep,
		const FHitResult &sweepResult);
};
