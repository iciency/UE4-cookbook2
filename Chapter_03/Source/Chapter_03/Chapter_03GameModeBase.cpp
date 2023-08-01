// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_03GameModeBase.h"
#include "Action.h"

void AChapter_03GameModeBase::BeginPlay()
{
	
	UE_LOG(LogTemp, Warning, TEXT("시작됨"))
	UAction * action = NewObject<UAction>(GetTransientPackage(),
		UAction::StaticClass());

	action->ConditionalBeginDestroy();
}

