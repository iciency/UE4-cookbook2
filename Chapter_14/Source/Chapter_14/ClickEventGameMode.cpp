// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickEventGameMode.h"

void AClickEventGameMode::BeginPlay()
{
	Super::BeginPlay();

	widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
	[
		SNew(SButton).OnClicked(FOnClicked::CreateUObject(this, &AClickEventGameMode::ButtonClicked)).Content()
		[
			SAssignNew(ButtonLabel, STextBlock)
			.Text(FText::FromString(TEXT("Click me!")))
		]
	];
	auto player = GetWorld()->GetFirstLocalPlayerFromController();

	GEngine->GameViewport->AddViewportWidgetForPlayer(player, widget.ToSharedRef(), 1);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	auto pc = GEngine->GetFirstLocalPlayerController(GetWorld());

	EMouseLockMode LockMode = EMouseLockMode::DoNotLock;

	auto inputMode = FInputModeUIOnly().SetLockMouseToViewportBehavior(LockMode).SetWidgetToFocus(widget);

	pc->SetInputMode(inputMode);
}

FReply AClickEventGameMode::ButtonClicked()
{
	ButtonLabel->SetText(FText::FromString(TEXT("Clicked!")));
	return FReply::Handled();
}
