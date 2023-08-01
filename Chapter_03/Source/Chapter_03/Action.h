// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Action.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType,
	meta = (ShortTooltip = "Base Class for any Action type"))
class CHAPTER_03_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
	FKey ShortcutKey;

	
};
