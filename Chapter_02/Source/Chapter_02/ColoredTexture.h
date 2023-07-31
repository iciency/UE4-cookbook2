﻿#pragma once

#include "UObject/ObjectMacros.h"
#include "ColoredTexture.generated.h"

USTRUCT(BlueprintType)
struct CHAPTER_02_API FColoredTexture
{
	GENERATED_USTRUCT_BODY()
	
public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = HUD )
	UTexture* Texture;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = HUD )    
	FLinearColor Color;
};