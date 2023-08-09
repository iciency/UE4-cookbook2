// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_11GameModeBase.h"
#include "Chapter_11.h"
#include "Warrior.h"


AChapter_11GameModeBase::AChapter_11GameModeBase()
{
	DefaultPawnClass = AWarrior::StaticClass();
}

void AChapter_11GameModeBase::BeginPlay()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Message %d"),1);

	UE_LOG(LogCh11,Display,TEXT("A warning message, log is working"));
	UE_LOG(LogCh11, Warning,TEXT("Awarning message"));
	UE_LOG(LogCh11, Error,TEXT("An error message"));

	CreateLog(LoggerName);
	
	FMessageLog logger(LoggerName);
	logger.Warning(FTEXT("A warning message from gamemode"));
	logger.Info(FTEXT("info to log"));
	logger.Warning(FTEXT("Warning text to log"));
	logger.Error(FTEXT("Error text to log"));
}

