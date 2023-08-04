// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_06GameModeBase.h"
#include "Blueprint/UserWidget.h"

void AChapter_06GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("True"));
	
	if(Widget)
	{
		UE_LOG(LogTemp, Warning, TEXT("True Widget"));
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);

		if(Menu)
		{
			UE_LOG(LogTemp, Warning, TEXT("True Menu"));
			Menu->AddToViewport();
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		}
	}
}
