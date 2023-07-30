// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_01GameMode.generated.h"


UCLASS()
class CHAPTER_01_API AChapter_01GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void BeginPlay();
	AChapter_01GameMode();

};



