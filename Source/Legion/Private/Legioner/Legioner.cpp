// Fill out your copyright notice in the Description page of Project Settings.


#include "Legion/Public/Legioner/Legioner.h"
#include "Components/LegionerStateComponent.h"

ALegioner::ALegioner()
{
	PrimaryActorTick.bCanEverTick = false;

	LegionerStateComponent = CreateDefaultSubobject<ULegionerStateComponent>("LegionerStateComponent");
}
