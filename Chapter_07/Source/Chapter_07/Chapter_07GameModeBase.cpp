// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_07GameModeBase.h"
#include "EngineUtils.h"
#include "MyInterface.h"
#include "SingleInterfaceActor.h"

void AChapter_07GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation;
	ASingleInterfaceActor* SpawnedActor = GetWorld()->SpawnActor<ASingleInterfaceActor>(
		ASingleInterfaceActor::StaticClass(),SpawnLocation);

	UClass* ActorClass = SpawnedActor->GetClass();

	if(ActorClass->ImplementsInterface(UMyInterface::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("Spawned actor implements interface!"));
	}
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor* Actor = *It;

		IMyInterface* MyInterfaceInstance = Cast<IMyInterface>(Actor);

		if(MyInterfaceInstance)
		{
			MyInterfaceInstances.Add(MyInterfaceInstance);
		}
	}
	FString Message = FString::Printf(TEXT("%d actors Implement the interface"),MyInterfaceInstances.Num());

	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,Message);
}
