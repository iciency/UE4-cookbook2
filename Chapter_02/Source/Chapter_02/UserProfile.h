// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColoredTexture.h"
#include "EnumName.h"
#include "Containers/EnumAsByte.h"
#include "UserProfile.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CHAPTER_02_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = stats)
	float Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = stats)
	float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = stats)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	FSoftObjectPath UClassGameMode;

	//Custom struct example
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = HUD)
	FColoredTexture Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = stats)
	TEnumAsByte<EStatus> Status;
};
