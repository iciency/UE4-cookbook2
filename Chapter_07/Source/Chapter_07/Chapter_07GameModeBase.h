// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_07GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_07_API AChapter_07GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	TArray<IMyInterface*> MyInterfaceInstances;
};
