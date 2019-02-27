// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();
	float CurrentThrottle = 0;

public:
	//Max force per track in Newtons
	//A modern medium tank weight is 30-35 tons, so 30000-35000kg, I choosed to be 35000kg the weight of our tank
	//0-56kmph in 10 seconds needs an acceleration of 0-1556 meters squared and that is achivied with
	//0 to 0.1587 g (standart accelerationdue to gravity on the surface of the earth)
	//Som 0.1587 g is equal to 1.556315 meter/square second
	//So, we have 2 tracks to move the tank and the force we need to produce that behave is divided by 2
	//F = ((35000 * 1.556315)/2)
	//F = 27235.5125 Newtons
	//assuming that value is too slow for a game to be fun and we have a lot of friction I will multiply by 1000
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;

	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);
};
