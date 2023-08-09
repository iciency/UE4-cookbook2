// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"
#include "GameplayAbilitySet.h"
#include "GameUnitAttributeSet.h"
#include "AbilitySystemComponent.h"


// Sets default values
AWarrior::AWarrior()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);

	AbilitySystemComponent->BindToInputComponent(Input);

	for (const FGameplayAbilityBindInfo& BindInfo : GameplayAbilitySet->Abilities)
	{
		FGameplayAbilitySpec spec(BindInfo.GameplayAbilityClass->GetDefaultObject<UGameplayAbility>(), 1,
		                          BindInfo.Command);

		FGameplayAbilitySpecHandle abilityHandle = AbilitySystemComponent->GiveAbility(spec);

		int32 AbilityID = (int32)BindInfo.Command;

		FGameplayAbilityInputBinds InputBinds(

			FS("ConfirTargetting_%s_%s", *GetName(),
			   *BindInfo.GameplayAbilityClass->GetName()),
			FS("CancelTargetting_%s_%s", *GetName(),
			   *BindInfo.GameplayAbilityClass->GetName()), "EGameplayAbilityInputBinds",
			AbilityID, AbilityID
		);
		AbilitySystemComponent->BindAbilityActivationToInputComponent(Input, InputBinds);

		AbilitySystemComponent->TryActivateAbility(abilityHandle, true);
	}
}

void AWarrior::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitStats(UGameUnitAttributeSet::StaticClass(), nullptr);
	}
}


inline UGameplayEffect* ConstructGameplayEffect(FString name)
{
	return NewObject<UGameplayEffect>(GetTransientPackage(), FName(*name));
}

inline FGameplayModifierInfo& AddModifier(UGameplayEffect* Effect,
                                          FProperty* Property,
                                          EGameplayModOp::Type op,
                                          const FGameplayEffectModifierMagnitude& Magnitude)
{
	int32 index = Effect->Modifiers.Num();
	Effect->Modifiers.SetNum(index +1);
	FGameplayModifierInfo& info =Effect->Modifiers[index];
	info.ModifierMagnitude = Magnitude;
	info.ModifierOp = op;
	info.Attribute.SetUProperty(Property);
	return info;
}

void AWarrior::TestGameplayEffect()
{
	UGameplayEffect* RecoverHP = ConstructGameplayEffect("RecoverHP");
	FProperty* hpProperty = FindFieldChecked<FProperty>(
		UGameUnitAttributeSet::StaticClass(),
		GET_MEMBER_NAME_CHECKED(UGameUnitAttributeSet, Hp));

	AddModifier(RecoverHP, hpProperty, EGameplayModOp::Additive, FScalableFloat(50.f));

	RecoverHP->DurationPolicy = EGameplayEffectDurationType::HasDuration;
	RecoverHP->DurationMagnitude = FScalableFloat(10.f);
	RecoverHP->ChanceToApplyToTarget = 1.f;

	FActiveGameplayEffectHandle recoverHpEffectHandle =
	  AbilitySystemComponent->ApplyGameplayEffectToTarget(
		  RecoverHP, AbilitySystemComponent, 1.f);
}