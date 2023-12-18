// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Legioner/LegionerState.h"
#include "LegionerStateComponent.generated.h"

enum class ELegionerState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChange, ELegionerState, NewState);

UCLASS(ClassGroup=(Legioner), meta=(BlueprintSpawnableComponent))
class LEGION_API ULegionerStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULegionerStateComponent();

	UFUNCTION(BlueprintCallable)
	ELegionerState GetCurrentState() const { return CurrentState; }

	UFUNCTION(BlueprintCallable)
	void ChangeState(ELegionerState NewState);

	UPROPERTY(BlueprintCallable)
	FOnStateChange OnStateChange;

private:
	ELegionerState CurrentState = ELegionerState::Invalid;
};
