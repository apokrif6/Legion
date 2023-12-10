// Copyright Epic Games, Inc. All Rights Reserved.

#include "LegionGameMode.h"
#include "LegionCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALegionGameMode::ALegionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
