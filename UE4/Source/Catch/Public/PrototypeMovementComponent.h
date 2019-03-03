// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicMovementBase.h"
#include "PrototypeMovementComponent.generated.h"


UENUM()
enum class EProtoMovementState : uint8
{
	Idle,
	MovingLeft,
	MovingRight,
	DashLeft,
	DashRight,
	Dashing
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CATCH_API UPrototypeMovementComponent : public UBasicMovementBase
{
	GENERATED_BODY()

	UPrototypeMovementComponent();

public:
	void BeginPlay() override;
	void TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

protected:
	void OnNothingToLeft(float timeSeconds) override;
	void OnNothingToRight(float timeSeconds) override;
	void OnLeftToNothing(float timeSeconds) override;
	void OnRightToNothing(float timeSeconds) override;
	void OnBothToLeft(float timeSeconds) override;
	void OnBothToRight(float timeSeconds) override;

private:
	EProtoMovementState _moveState;
	EProtoMovementState _dashQueuedMovementState;
	APawn* _owner{};
	float _lastDashTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float _movementInputScale;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float _doublePressIntervalSeconds;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float _dashDurationSeconds;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float _postDashInputLag;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float _dashInputScale;

	void IdleToMovingLeft(float timeSeconds);
	void IdleToMovingRight(float timeSeconds);
	void MovingRightToIdle(float timeSeconds);
	void MovingLeftToIdle(float timeSeconds);
	void IdleToDashingLeft(float timeSeconds);
	void IdleToDashingRight(float timeSeconds);
	// void DashingLeftToIdle();
	// void DashingRightToIdle();
	// void DashingLeftToMovingLeft();
	// void DashingLeftToMovingRight();
	// void DashingRightToMovingLeft();
	// void DashingRightToMovingRight();
};
