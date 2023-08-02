// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior2.h"

// Sets default values
AWarrior2::AWarrior2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWarrior2::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(10);
}

// Called every frame
void AWarrior2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

