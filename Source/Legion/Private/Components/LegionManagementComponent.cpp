// Fill out your copyright notice in the Description page of Project Settings.


#include "Legion/Public/Components/LegionManagementComponent.h"
#include "NavigationSystem.h"
#include "Legion/Public/Legioner/Legioner.h"

ULegionManagementComponent::ULegionManagementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool ULegionManagementComponent::SpawnLegioner()
{
	if (!CurrentChosenLegioner)
		return false;

	ALegioner* SpawnedLegioner = GetWorld()->SpawnActor<ALegioner>(CurrentChosenLegioner, GetTransformForSpawn());
	if (!SpawnedLegioner)
		return false;

	SpawnedLegioners.Add(SpawnedLegioner);

	return true;
}

void ULegionManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!AvailableLegioners.IsEmpty())
	{
		CurrentChosenLegioner = AvailableLegioners[0];
	}
}

FTransform ULegionManagementComponent::GetTransformForSpawn() const
{
	const FVector Origin = GetOwner()->GetActorLocation();
	FNavLocation RandomPoint(Origin);

	if (const UNavigationSystemV1* NavigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld()))
	{
		NavigationSystem->GetRandomReachablePointInRadius(Origin, SpawnRadius, RandomPoint);
	}

	return FTransform(GetOwner()->GetActorRotation() ,RandomPoint.Location);
}
