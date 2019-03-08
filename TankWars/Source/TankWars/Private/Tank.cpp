// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Delegates/Delegate.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;

	/* ### Other way ###
	// Call the base class - this will tell us how much damage to apply
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		auto RealDamage = FMath::Clamp(ActualDamage, 0.0f, CurrentHealth);
		CurrentHealth -= RealDamage;

		UE_LOG(LogTemp, Warning, TEXT("Tank: %s , Damage: %f , Taken: %f , Current Health: %f"), *GetName(), ActualDamage, RealDamage, CurrentHealth);

		// If the damage depletes our health set our lifespan to zero - which will destroy the actor
		if (CurrentHealth <= 0.f)
		{
			SetLifeSpan(0.001f);
		}
	}
	return ActualDamage;
	*/
}


float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}