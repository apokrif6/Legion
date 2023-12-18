// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/LegionerStateComponent.h"

ULegionerStateComponent::ULegionerStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULegionerStateComponent::ChangeState(const ELegionerState NewState)
{
	if (CurrentState == NewState)
		return;

	CurrentState = NewState;

	OnStateChange.Broadcast(NewState);
}
