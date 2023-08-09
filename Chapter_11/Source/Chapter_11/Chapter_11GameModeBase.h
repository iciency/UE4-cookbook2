// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_11GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_11_API AChapter_11GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	AChapter_11GameModeBase();
};
