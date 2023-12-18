// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "LegionerController.generated.h"

enum class ELegionerState : uint8;

UCLASS()
class LEGION_API ALegionerController : public AAIController
{
	GENERATED_BODY()

public:
	ALegionerController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	TMap<ELegionerState, UBehaviorTree*> StateBehaviors;

private:
	UFUNCTION()
	void RunBehaviorOnChangedState(ELegionerState NewState);
};
