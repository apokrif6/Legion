// Fill out your copyright notice in the Description page of Project Settings.

#include "Legioner/LegionerController.h"
#include "Legioner/Legioner.h"
#include "Components/LegionerStateComponent.h"

ALegionerController::ALegionerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALegionerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const ALegioner* Legioner = GetPawn<ALegioner>();
	if (!Legioner) return;

	ULegionerStateComponent* LegionerStateComponent = Legioner->GetComponentByClass<ULegionerStateComponent>();
	if (!LegionerStateComponent) return;

	LegionerStateComponent->OnStateChange.AddDynamic(this, &ThisClass::RunBehaviorOnChangedState);
}

void ALegionerController::RunBehaviorOnChangedState(const ELegionerState NewState)
{
	if (StateBehaviors.Contains(NewState))
	{
		RunBehaviorTree(StateBehaviors[NewState]);
	}
}
