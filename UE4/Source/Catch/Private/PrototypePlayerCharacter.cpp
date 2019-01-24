// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypePlayerCharacter.h"
#include "PrototypeMovementComponent.h"
#include "BasicMovementBase.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

APrototypePlayerCharacter::APrototypePlayerCharacter(const FObjectInitializer& ObjectInitializer) :
		Super(ObjectInitializer.SetDefaultSubobjectClass<UPrototypeMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

	_boxComponent = CreateDefaultSubobject<UBoxComponent>(FName("Capsule Collision Component"));
	_boxComponent->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void APrototypePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}
