// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

UPrototypeMovementComponent::UPrototypeMovementComponent() :
		_moveState(EProtoMovementState::Idle),
		_dashQueuedMovementState(EProtoMovementState::Idle),
		_lastDashTimeSeconds(-10),
		_movementInputScale(1.0),
		_doublePressIntervalSeconds(.2),
		_dashDurationSeconds(.25),
		_postDashInputLag(.75),
		_dashInputScale(5.0),
		_maxRowSpeed(300),
		_maxDashSpeed(700)
{
}

void UPrototypeMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto ownerActor = GetOwner();

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
	MaxSwimSpeed = _maxRowSpeed;
}

void UPrototypeMovementComponent::TickComponent(
	const float deltaTime,
	const ELevelTick tickType,
	FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	switch(_moveState)
	{
	case EProtoMovementState::Idle:
		break;

	case EProtoMovementState::MovingLeft:
		_owner->AddMovementInput(FVector(-1.0, 0.0, 0.0), _movementInputScale);
		break;

	case EProtoMovementState::MovingRight:
		_owner->AddMovementInput(FVector(1.0, 0.0, 0.0), _movementInputScale);
		break;

	case EProtoMovementState::DashLeft:
		if (GetWorld()->GetTimeSeconds() - _lastDashTimeSeconds < _dashDurationSeconds)
		{
			_owner->AddMovementInput(FVector(-1.0, 0.0, 0.0), _dashInputScale);
			break;
		}
		_moveState = EProtoMovementState::Dashing;
		break;

	case EProtoMovementState::DashRight:
		if (GetWorld()->GetTimeSeconds() - _lastDashTimeSeconds < _dashDurationSeconds)
		{
			_owner->AddMovementInput(FVector(1.0, 0.0, 0.0), _dashInputScale);
			break;
		}
		_moveState = EProtoMovementState::Dashing;
		break;

	case EProtoMovementState::Dashing:
		if (GetWorld()->GetTimeSeconds() - _lastDashTimeSeconds > _dashDurationSeconds + _postDashInputLag) 
		{
			_moveState = _dashQueuedMovementState;
			MaxSwimSpeed = _maxRowSpeed;
		}
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("Move state not implemented."));
		break;
	}
}

//INPUT STATE FUNCTIONS
void UPrototypeMovementComponent::OnNothingToLeft(const float timeSeconds)
{
	if (_moveState == EProtoMovementState::Idle)
	{
		if (timeSeconds - GetLastLeftPressTime() < _doublePressIntervalSeconds)
			IdleToDashingLeft(timeSeconds);
		else
			IdleToMovingLeft(timeSeconds);
	}
	else if (_moveState == EProtoMovementState::Dashing)
		_dashQueuedMovementState = EProtoMovementState::MovingLeft;
}

void UPrototypeMovementComponent::OnNothingToRight(const float timeSeconds)
{
	if (_moveState == EProtoMovementState::Idle)
	{
		if (timeSeconds - GetLastRightPressTime() < _doublePressIntervalSeconds)
			IdleToDashingRight(timeSeconds);
		else
			IdleToMovingRight(timeSeconds);
	}
	else if (_moveState == EProtoMovementState::Dashing)
		_dashQueuedMovementState = EProtoMovementState::MovingRight;
}

void UPrototypeMovementComponent::OnLeftToNothing(const float timeSeconds)
{
	if (_moveState == EProtoMovementState::MovingLeft)
		MovingLeftToIdle(timeSeconds);
	else if (_moveState == EProtoMovementState::Dashing)
		_dashQueuedMovementState = EProtoMovementState::Idle;
}

void UPrototypeMovementComponent::OnRightToNothing(const float timeSeconds)
{
	if (_moveState == EProtoMovementState::MovingRight)
		MovingRightToIdle(timeSeconds);
	else if (_moveState == EProtoMovementState::Dashing)
		_dashQueuedMovementState = EProtoMovementState::Idle;
}

void UPrototypeMovementComponent::OnBothToLeft(const float timeSeconds)
{
	OnNothingToLeft(timeSeconds);
}

void UPrototypeMovementComponent::OnBothToRight(const float timeSeconds)
{
	OnNothingToRight(timeSeconds);
}

//CHARACTER STATE FUNCTIONS
void UPrototypeMovementComponent::IdleToMovingLeft(const float timeSeconds)
{
	_moveState = EProtoMovementState::MovingLeft;
}

void UPrototypeMovementComponent::IdleToMovingRight(const float timeSeconds)
{
	_moveState = EProtoMovementState::MovingRight;
}

void UPrototypeMovementComponent::MovingRightToIdle(const float timeSeconds)
{
	_moveState = EProtoMovementState::Idle;
}

void UPrototypeMovementComponent::MovingLeftToIdle(const float timeSeconds)
{
	_moveState = EProtoMovementState::Idle;
}

void UPrototypeMovementComponent::IdleToDashingLeft(const float timeSeconds)
{
	_lastDashTimeSeconds = timeSeconds;
	_moveState = EProtoMovementState::DashLeft;
	MaxSwimSpeed = _maxDashSpeed;
}

void UPrototypeMovementComponent::IdleToDashingRight(const float timeSeconds)
{
	_lastDashTimeSeconds = timeSeconds;
	_moveState = EProtoMovementState::DashRight; 
	MaxSwimSpeed = _maxDashSpeed;
}
