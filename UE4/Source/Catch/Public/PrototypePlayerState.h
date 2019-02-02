// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PrototypePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CATCH_API APrototypePlayerState : public APlayerState
{
	GENERATED_BODY()

	APrototypePlayerState();

public:
	void OnCatch();

private:
	int _score;
};
