// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypePlayerState.h"
#include <string>
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

APrototypePlayerState::APrototypePlayerState() :
	_score(0)
{
}

void APrototypePlayerState::OnCatch()
{
	_score++;
	UE_LOG(LogTemp, Warning, TEXT("Score: %d"), _score);
}
