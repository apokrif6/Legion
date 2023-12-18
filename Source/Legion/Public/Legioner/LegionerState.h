// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LegionerState.generated.h"

UENUM(BlueprintType)
enum class ELegionerState : uint8
{
	Invalid UMETA(Hidden),
	Spawning,
	Attacking,
	Blocking,
};
