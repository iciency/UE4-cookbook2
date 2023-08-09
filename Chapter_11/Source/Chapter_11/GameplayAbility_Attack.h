// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_Attack.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_11_API UGameplayAbility_Attack : public UGameplayAbility
{
	GENERATED_BODY()

	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
	                                const FGameplayAbilityActorInfo* ActorInfo,
	                                const FGameplayTagContainer* SourceTags,
	                                const FGameplayTagContainer* TargetTags,
	                                FGameplayTagContainer* OptionalRelevantTags) const override
	{
		UE_LOG(LogTemp, Warning, TEXT("ability_attack CanActivateAbility!"));
		return true;
	}

	virtual bool CheckCost(const FGameplayAbilitySpecHandle Handle,
	                       const FGameplayAbilityActorInfo* ActorInfo,
	                       FGameplayTagContainer* OptionalRelevantTags) const override
	{
		UE_LOG(LogTemp, Warning, TEXT("ability_Attack CheckCost!"));
		return false;
	}

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	                             const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo,
	                             const FGameplayEventData* TriggerEventData) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Activating Ugameplayabillity_attack()"));
		Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	}

	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle,
	                          const FGameplayAbilityActorInfo* ActorInfo,
	                          const FGameplayAbilityActivationInfo ActivationInfo) override
	{
		UE_LOG(LogTemp, Warning, TEXT("ability_attack inputpressed"));
		Super::InputPressed(Handle, ActorInfo, ActivationInfo);
	}
};
