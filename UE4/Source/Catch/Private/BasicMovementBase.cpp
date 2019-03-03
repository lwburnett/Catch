// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicMovementBase.h"

UBasicMovementBase::UBasicMovementBase():
		_isLeftPressed(false),
		_isRightPressed(false),
		_leftLastPressedTime(-10),
		_rightLastPressedTime(-10)
{
}

void UBasicMovementBase::HandleLeftPressed(const float timeSeconds)
{
	if (_isLeftPressed)
		return;

	_isLeftPressed = true;

	if (_isRightPressed)
		OnRightToBoth(timeSeconds);

	else
		OnNothingToLeft(timeSeconds);

	_leftLastPressedTime = timeSeconds;
}

// ReSharper disable once CppParameterNeverUsed
void UBasicMovementBase::HandleLeftReleased(const float timeSeconds)
{
	if (!_isLeftPressed)
		return;

	_isLeftPressed = false;

	if (_isRightPressed)
		OnBothToRight(timeSeconds);

	else
		OnLeftToNothing(timeSeconds);
}

void UBasicMovementBase::HandleRightPressed(const float timeSeconds)
{
	if (_isRightPressed)
		return;

	_isRightPressed = true;

	if (_isLeftPressed)
		OnLeftToBoth(timeSeconds);

	else
		OnNothingToRight(timeSeconds);

	_rightLastPressedTime = timeSeconds;
}

// ReSharper disable once CppParameterNeverUsed
void UBasicMovementBase::HandleRightReleased(const float timeSeconds)
{
	if (!_isRightPressed)
		return;

	_isRightPressed = false;

	if (_isLeftPressed)
		OnBothToLeft(timeSeconds);

	else
		OnRightToNothing(timeSeconds);
}

float UBasicMovementBase::GetLastLeftPressTime() const
{
	return _leftLastPressedTime;
}

float UBasicMovementBase::GetLastRightPressTime() const
{
	return _rightLastPressedTime;
}
