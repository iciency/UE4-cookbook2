// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleObject.h"

#include "Components/SphereComponent.h"

// Sets default values
ACollectibleObject::ACollectibleObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	USphereComponent* SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphrerComponent"));

	RootComponent = SphereCollider;

	SphereCollider->InitSphereRadius(64.0f);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleObject::OnBeginOverlap);

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SphereVisual->SetupAttachment(RootComponent);

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(
		TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	if (MeshAsset.Object != nullptr)
	{
		SphereVisual->SetStaticMesh(MeshAsset.Object);
	}

	SphereVisual->SetWorldScale3D(FVector(0.5f));
}

void ACollectibleObject::OnBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		UpdateScore(1);
		Destroy();
	}
}

void ACollectibleObject::UpdateScore_Implementation(int32 Amount)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Collected!");
	}
}

bool ACollectibleObject::UpdateScore_Validate(int32 Amount)
{
	return true;
}

// Called when the game starts or when spawned
void ACollectibleObject::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACollectibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
