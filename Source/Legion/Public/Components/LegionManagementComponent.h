﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LegionManagementComponent.generated.h"

enum class ELegionerState : uint8;
class ALegioner;

UCLASS(ClassGroup=(Legion), meta=(BlueprintSpawnableComponent))
class LEGION_API ULegionManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULegionManagementComponent();

	bool SpawnLegioner();

	const TArray<ALegioner*>& GetSpawnedLegioners() const { return SpawnedLegioners; }

	void ChangeStatesForLegioners(const ELegionerState NewState);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	TArray<TSubclassOf<ALegioner>> AvailableLegioners;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	float SpawnRadius = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	int32 Limit = 3;
	
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<ALegioner*> SpawnedLegioners;

	TSubclassOf<ALegioner> CurrentChosenLegioner;

	FTransform GetTransformForSpawn() const;
};
