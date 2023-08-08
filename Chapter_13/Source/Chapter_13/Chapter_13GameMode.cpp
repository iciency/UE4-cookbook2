// Copyright Epic Games, Inc. All Rights Reserved.

#include "Chapter_13GameMode.h"
#include "Chapter_13Character.h"
#include "UObject/ConstructorHelpers.h"

AChapter_13GameMode::AChapter_13GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
