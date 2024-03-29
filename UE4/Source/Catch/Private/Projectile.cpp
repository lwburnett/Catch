// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_movementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	_movementComponent->Deactivate();

	_capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("Capsule Collision Component"));
	SetRootComponent(_capsuleComponent);
	_capsuleComponent->SetNotifyRigidBodyCollision(true);
	_capsuleComponent->SetVisibility(true);
}

void AProjectile::Launch(const FVector launchVector) const
{
	if(!ensure(_movementComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("No movement component found for projectile!"));
		return;
	}
	_movementComponent->Activate();
	_movementComponent->SetVelocityInLocalSpace(launchVector);
}

void AProjectile::OnHitReflectiveWall() const
{
	const auto currentVelocity = GetVelocity();
	const auto targetVelocity = FVector(-1 * currentVelocity.X, currentVelocity.Y, currentVelocity.Z);
	_movementComponent->SetVelocityInLocalSpace(targetVelocity);
}

void AProjectile::OnCaught() 
{
	UE_LOG(LogTemp, Warning, TEXT("Caught!"));
	Destroy();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

