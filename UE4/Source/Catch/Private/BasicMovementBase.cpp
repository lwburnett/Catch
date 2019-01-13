// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicMovementBase.h"

UBasicMovementBase::UBasicMovementBase():
		_isLeftPressed(false),
		_isRightPressed(false)
{
}

void UBasicMovementBase::HandleLeftPressed()
{
	if (_isLeftPressed)
		return;

	_isLeftPressed = true;

	if (_isRightPressed)
		OnRightToBoth();

	else
		OnNothingToLeft();
}

void UBasicMovementBase::HandleLeftReleased()
{
	if (!_isLeftPressed)
		return;

	_isLeftPressed = false;

	if (_isRightPressed)
		OnBothToRight();

	else
		OnLeftToNothing();
}

void UBasicMovementBase::HandleRightPressed()
{
	if (_isRightPressed)
		return;

	_isRightPressed = true;

	if (_isLeftPressed)
		OnLeftToBoth();

	else
		OnNothingToRight();
}

void UBasicMovementBase::HandleRightReleased()
{
	if (!_isRightPressed)
		return;

	_isRightPressed = false;

	if (_isLeftPressed)
		OnBothToLeft();

	else
		OnRightToNothing();
}
