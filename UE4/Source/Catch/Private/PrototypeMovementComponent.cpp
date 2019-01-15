// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeMovementComponent.h"
#include "GameFramework/Pawn.h"

void UPrototypeMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	auto ownerActor = GetOwner();

	if (!ensure(ownerActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find owner."));
		return;
	}

	const auto owner = Cast<APawn>(ownerActor);

	if (!ensure(owner))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find owner."));
		return;
	}

	_owner = owner;
}

void UPrototypeMovementComponent::TickComponent(
	float deltaTime, 
	ELevelTick tickType,
	FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	switch(_moveState)
	{
	case EProtoMovementState::Idle:
		break;

	case EProtoMovementState::MovingLeft:
		_owner->AddMovementInput(FVector(-1.0, 0.0, 0.0), 1.0);
		break;

	case EProtoMovementState::MovingRight:
		_owner->AddMovementInput(FVector(1.0, 0.0, 0.0), 1.0);
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("Move state not implemented."));
		break;
	}
}

void UPrototypeMovementComponent::OnNothingToLeft()
{
	UE_LOG(LogTemp, Warning, TEXT("Move state set left."));
	_moveState = EProtoMovementState::MovingLeft;
}

void UPrototypeMovementComponent::OnNothingToRight()
{
	UE_LOG(LogTemp, Warning, TEXT("Move state set right."));
	_moveState = EProtoMovementState::MovingRight;
}

void UPrototypeMovementComponent::OnLeftToNothing()
{
	UE_LOG(LogTemp, Warning, TEXT("Move state set idle."));
	_moveState = EProtoMovementState::Idle;
}

void UPrototypeMovementComponent::OnRightToNothing()
{
	OnLeftToNothing();
}
