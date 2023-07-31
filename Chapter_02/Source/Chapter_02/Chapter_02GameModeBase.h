// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UserProfile.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_02GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_02_API AChapter_02GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<UUserProfile> UPBlueprintClassName;
};
