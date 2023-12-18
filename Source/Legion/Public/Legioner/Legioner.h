// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Legioner.generated.h"

class ULegionerStateComponent;

UCLASS()
class LEGION_API ALegioner : public ACharacter
{
	GENERATED_BODY()

public:
	ALegioner();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ULegionerStateComponent* LegionerStateComponent;
};
