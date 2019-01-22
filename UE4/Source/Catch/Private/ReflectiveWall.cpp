// Fill out your copyright notice in the Description page of Project Settings.

#include "ReflectiveWall.h"
#include "Projectile.h"

// Sets default values
AReflectiveWall::AReflectiveWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("Capsule Collision Component"));
	SetRootComponent(_capsuleComponent);
	_capsuleComponent->SetNotifyRigidBodyCollision(true);
	_capsuleComponent->SetVisibility(true);
}

void AReflectiveWall::BeginPlay()
{
	Super::BeginPlay();

	_capsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AReflectiveWall::OnBeginOverlap);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AReflectiveWall::OnBeginOverlap(
	UPrimitiveComponent* overlappedComponent,
	AActor* otherActor,
	UPrimitiveComponent* otherComp,
	int32 otherBodyIndex,
	bool bFromSweep,
	const FHitResult &sweepResult)
{
	const auto projectile = Cast<AProjectile>(otherActor);
	if(projectile)
	{
		projectile->OnHitReflectiveWall();
	}
}

