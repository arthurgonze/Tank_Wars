// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward speed and +1 is max upward speed
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 15;
};
