// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlatformerPuzzleGameMode.h"
#include "PlatformerPuzzleCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlatformerPuzzleGameMode::APlatformerPuzzleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
