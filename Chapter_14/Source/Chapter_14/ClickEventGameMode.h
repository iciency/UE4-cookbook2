// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ClickEventGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_14_API AClickEventGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	TSharedPtr<SVerticalBox> widget;
	TSharedPtr<STextBlock> ButtonLabel;

public:
	virtual void BeginPlay() override;
	FReply ButtonClicked();
};
