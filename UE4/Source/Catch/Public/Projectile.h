// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UCapsuleComponent;
class UProjectileMovementComponent;

UCLASS()
class CATCH_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void Launch(FVector launchVector) const;

	virtual void OnHitReflectiveWall() const;

	virtual void OnCaught();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, category = "Components")
	UCapsuleComponent* _capsuleComponent;


	UProjectileMovementComponent* _movementComponent;
};
