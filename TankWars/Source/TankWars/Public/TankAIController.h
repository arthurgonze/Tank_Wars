// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	ATank* GetAIControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void PrintAIControlledTank();
	void PrintPlayerControlledTank();

	ATank* GetPlayerControlledTank() const;

	void AimTowardsPlayer();
};