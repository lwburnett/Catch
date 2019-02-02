// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypePlayerCharacter.h"
#include "PrototypeMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "PrototypePlayerState.h"
#include "Projectile.h"

APrototypePlayerCharacter::APrototypePlayerCharacter(const FObjectInitializer& objectInitializer) :
		Super(objectInitializer.SetDefaultSubobjectClass<UPrototypeMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

	_boxComponent = CreateDefaultSubobject<UBoxComponent>(FName("Capsule Collision Component"));
	_boxComponent->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void APrototypePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	_boxComponent->OnComponentBeginOverlap.AddDynamic(this, &APrototypePlayerCharacter::OnCatch);
}

void APrototypePlayerCharacter::OnCatch(
	UPrimitiveComponent* overlappedComponent, 
	AActor* otherActor,
	UPrimitiveComponent* otherComp, 
	int32 otherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& sweepResult)
{
	const auto projectile = Cast<AProjectile>(otherActor);
	if (projectile)
	{
		projectile->OnCaught();
		auto playerState = Cast<APrototypePlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
		playerState->OnCatch();
	}
}
