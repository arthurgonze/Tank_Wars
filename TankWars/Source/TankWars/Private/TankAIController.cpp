// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PrintAIControlledTank();

	UE_LOG(LogTemp, Warning, TEXT("AIController %s begin play"), *(this->GetName()));
	
	PrintPlayerControlledTank();
}

void ATankAIController::PrintAIControlledTank()
{
	auto ControlledTank = GetAIControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController %s not possessing a tank"), *(this->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController %s possessing: %s"), *(this->GetName()), *(ControlledTank->GetName()));
	}
}

void ATankAIController::PrintPlayerControlledTank()
{
	auto playerControlledTank = GetPlayerControlledTank();
	if (!playerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController %s did not found a player tank"), *(this->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController %s found player tank: %s"), *(this->GetName()), *(playerControlledTank->GetName()));
	}
}

ATank * ATankAIController::GetPlayerControlledTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (playerPawn)
	{
		return Cast<ATank>(playerPawn);
	}
	else
	{
		return nullptr;
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
}

void ATankAIController::AimTowardsPlayer()
{
	if (!GetPlayerControlledTank() || !GetAIControlledTank())
	{
		return;
	}

	FVector HitLocation; // Out parameter
	GetPlayerControlledTank()->ActorToWorld().TransformPosition(HitLocation);

	GetAIControlledTank()->AimAt(HitLocation);
}
