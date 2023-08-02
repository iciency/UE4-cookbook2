// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchActor.h"

// Sets default values
AHierarchActor::AHierarchActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");

	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>
		(TEXT("StacticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		BoxOne->SetStaticMesh(MeshAsset.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	RootComponent = Root;

	BoxOne->K2_AttachTo(Root);
	BoxOne->K2_AttachTo(ChildSceneComponent);

	ChildSceneComponent->K2_AttachTo(Root);

	ChildSceneComponent->SetRelativeTransform(
		FTransform(
			FRotator(0, 0, 0),
			FVector(250, 0, 0),
			FVector(0.1f)));
}

// Called when the game starts or when spawned
void AHierarchActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHierarchActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
