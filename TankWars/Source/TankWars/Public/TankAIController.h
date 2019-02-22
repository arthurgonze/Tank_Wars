// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	//how close the AI tank get to the player
	float AcceptanceRadius = 1000;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
