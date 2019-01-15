// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "BasicMovementBase.generated.h"

UCLASS()
class CATCH_API UBasicMovementBase : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UBasicMovementBase();


	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleLeftPressed();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleLeftReleased();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleRightPressed();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void HandleRightReleased();

private:
	bool _isLeftPressed;
	bool _isRightPressed;

protected:
	virtual void OnNothingToLeft(){ }
	virtual void OnLeftToNothing(){ }
	virtual void OnLeftToBoth(){ }
	// TODO: virtual void OnDoubleLeft();
	virtual void OnNothingToRight(){ }
	virtual void OnRightToNothing(){ }
	virtual void OnRightToBoth(){ }
	// TODO: virtual void OnDoubleRight();

	// TODO: do these make sense? 
	// virtual void OnNothingToBoth();
	// virtual void OnBothToNothing();
	virtual void OnBothToLeft(){ }
	virtual void OnBothToRight(){ }
};
