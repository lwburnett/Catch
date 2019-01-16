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
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CATCH_API UPrototypeMovementComponent : public UBasicMovementBase
{
	GENERATED_BODY()


public:
	void BeginPlay() override;
	void TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

protected:
	void OnNothingToLeft() override;
	void OnNothingToRight() override;
	void OnLeftToNothing() override;
	void OnRightToNothing() override;
	void OnBothToLeft() override;
	void OnBothToRight() override;

private:
	EProtoMovementState _moveState;
	APawn* _owner;
};
