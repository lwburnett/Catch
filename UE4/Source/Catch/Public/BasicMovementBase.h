// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "BasicMovementBase.generated.h"

UCLASS()
class CATCH_API UBasicMovementBase : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UBasicMovementBase();


	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleLeftPressed(float timeSeconds);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleLeftReleased(float timeSeconds);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleRightPressed(float timeSeconds);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleRightReleased(float timeSeconds);

private:
	bool _isLeftPressed;
	bool _isRightPressed;
	float _leftLastPressedTime;
	float _rightLastPressedTime;

protected:
	float GetLastLeftPressTime() const;
	float GetLastRightPressTime() const;

	virtual void OnNothingToLeft(float timeSeconds){ }
	virtual void OnLeftToNothing(float timeSeconds){ }
	virtual void OnLeftToBoth(float timeSeconds){ }
	virtual void OnNothingToRight(float timeSeconds){ }
	virtual void OnRightToNothing(float timeSeconds){ }
	virtual void OnRightToBoth(float timeSeconds){ }

	// TODO: do these make sense? 
	// virtual void OnNothingToBoth();
	// virtual void OnBothToNothing();
	virtual void OnBothToLeft(float timeSeconds){ }
	virtual void OnBothToRight(float timeSeconds){ }
};
