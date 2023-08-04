// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"

#include "Chapter_06GameModeBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
AWarrior::AWarrior()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float len = lastInput.Size();

	if(len>1.f)
	{
		lastInput/= len;
	}
	AddMovementInput(GetActorForwardVector(), lastInput.Y);
	AddMovementInput(GetActorRightVector(), lastInput.X);

	lastInput = FVector2D(0.f,0.f);
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward);
	PlayerInputComponent->BindAxis("Back", this, &AWarrior::Back);
	PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
	PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior::Jump);

	FInputAxisKeyMapping BackKey("Back",EKeys::S,1.f);
	FInputActionKeyMapping Jump("Jump", EKeys::SpaceBar,0,0,0,0);

	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(BackKey);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddActionMapping(Jump);

	auto GameMode = Cast<AChapter_06GameModeBase>(GetWorld()->GetAuthGameMode());
	auto Func = &AChapter_06GameModeBase::ButtonClicked;
	
	if(GameMode && Func)
	{
		PlayerInputComponent->BindAction("HotKey_UIButton_Spell",IE_Pressed,GameMode, Func);
	}
}

void AWarrior::Forward(float amount)
{
	lastInput.Y += amount;
}

void AWarrior::Back(float amount)
{
	lastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{
	lastInput.X += amount;
}

void AWarrior::Left(float amount)
{
	lastInput.X -= amount;
}

void AWarrior::OnOverlapsBegin_Implementation(
	UPrimitiveComponent* Comp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("Overlaps warrior began"));
}


void AWarrior::OnOverlapsEnd_Implementation(
	UPrimitiveComponent* Comp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
	UE_LOG(LogTemp,Warning,TEXT("Overlaps warrior ended"));
}

void AWarrior::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(RootComponent)
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&AWarrior::OnOverlapsBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this,&AWarrior::OnOverlapsEnd);
	}
}
