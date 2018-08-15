// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

class UTankAimingComponent;

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	//How close Ai tank gets to player
	UPROPERTY(EditAnywhere, Category = Setup)
	float AcceptanceRadius = 3000;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};
