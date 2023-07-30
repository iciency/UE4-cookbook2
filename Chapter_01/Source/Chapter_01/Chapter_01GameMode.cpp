// Copyright Epic Games, Inc. All Rights Reserved.

#include "Chapter_01GameMode.h"
#include "Chapter_01Character.h"
#include "UObject/ConstructorHelpers.h"

void AChapter_01GameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("samting"));
	int intVar = 5;
	float floatVar = 3.7f;
	FString fstringVar = "an fstring variable";
	UE_LOG(LogTemp,Warning,TEXT("Text,%d %f %s"),intVar,floatVar,*fstringVar);
}

AChapter_01GameMode::AChapter_01GameMode()
{
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
