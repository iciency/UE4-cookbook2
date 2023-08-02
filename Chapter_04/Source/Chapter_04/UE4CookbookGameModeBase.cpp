// Fill out your copyright notice in the Description page of Project Settings.


#include "UE4CookbookGameModeBase.h"
#include "MyFirstActor.h"

void AUE4CookbookGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1,10, FColor::Red,TEXT("Actor Spawnning"));

	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>
	(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer,this,&AUE4CookbookGameModeBase::DestroyActorFunction, 10);
}

void AUE4CookbookGameModeBase::DestroyActorFunction()
{
	if(SpawnedActor != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1,10, FColor::Red, TEXT("Actor Destroyed"));

		SpawnedActor->Destroy();
	}
}
