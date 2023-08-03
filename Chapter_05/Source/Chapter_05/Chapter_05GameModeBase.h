// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_05GameModeBase.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FStanderDelegateSignture)
DECLARE_DELEGATE_OneParam(FParamDelegateSignture, FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
UCLASS()
class CHAPTER_05_API AChapter_05GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	FStanderDelegateSignture MyStanderDelegate;

	FParamDelegateSignture MyParameterDelegate;

	FMulticastDelegate MyMulticastDelegate;
};
