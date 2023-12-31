// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyFirstActor.h"
#include "GameFramework/GameModeBase.h"
#include "UE4CookbookGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_04_API AUE4CookbookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	AMyFirstActor* SpawnedActor;

	UFUNCTION()
	void DestroyActorFunction();
};
