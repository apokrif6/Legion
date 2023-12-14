// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LegionManagementComponent.generated.h"

class ALegioner;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LEGION_API ULegionManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULegionManagementComponent();

	bool SpawnLegioner();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	TArray<TSubclassOf<ALegioner>> AvailableLegioners;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	float SpawnRadius = 300.f;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<ALegioner*> SpawnedLegioners;

	TSubclassOf<ALegioner> CurrentChosenLegioner;

	FTransform GetTransformForSpawn() const;
};
