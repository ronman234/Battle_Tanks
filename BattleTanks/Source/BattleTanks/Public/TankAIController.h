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
	
private:

	//How close Ai tank gets to player
	float AcceptanceRadius = 3000;

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};
