// Copyright Epic Games, Inc. All Rights Reserved.

#include "ERDGameMode.h"
#include "ERDCharacter.h"
#include "UObject/ConstructorHelpers.h"

AERDGameMode::AERDGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
