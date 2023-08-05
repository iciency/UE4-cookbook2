// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractingPawn.h"

#include "Interactable.h"

// Sets default values
AInteractingPawn::AInteractingPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInteractingPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractingPawn::TryInteract()
{
	APlayerController* MyController = Cast<APlayerController>(Controller);

	if (MyController)
	{
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;

		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = StartLocation + (MyCameraManager->GetActorForwardVector() * 100);

		FCollisionObjectQueryParams Params;
		FHitResult HitResult;
		

		GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, 
											EndLocation, 
											FQuat::Identity,
											FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), 
											FCollisionShape::MakeSphere(25),
											FCollisionQueryParams(FName("Interaction"), true, this));

		if (HitResult.GetActor() != nullptr)
		{
			auto Class = HitResult.GetActor()->GetClass();
			if (Class->ImplementsInterface(UInteractable::StaticClass()))
			{
				if (IInteractable::Execute_CanInteract(HitResult.GetActor()))
				{
					IInteractable::Execute_PerformInteract(HitResult.GetActor());
				}
			}
		}
	}
}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}
