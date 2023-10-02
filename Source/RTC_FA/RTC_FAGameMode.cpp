// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTC_FAGameMode.h"
#include "RTC_FACharacter.h"
#include "UObject/ConstructorHelpers.h"

ARTC_FAGameMode::ARTC_FAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
