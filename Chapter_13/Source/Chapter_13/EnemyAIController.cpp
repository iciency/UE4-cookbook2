// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"

AEnemyAIController::AEnemyAIController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackbordComp"));
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AEnemyCharacter *EnemyCharacter = Cast<AEnemyCharacter>(InPawn);

	if(EnemyCharacter && EnemyCharacter->EnemyBehaviorTree)
	{
		BlackboardComp->InitializeBlackboard(*EnemyCharacter->EnemyBehaviorTree->BlackboardAsset);
		TargetKeyID = BlackboardComp->GetKeyID("Target");
		BehaviorComp->StartTree(*EnemyCharacter->EnemyBehaviorTree);
	}
}