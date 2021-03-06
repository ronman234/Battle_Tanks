// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurretComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreeperSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxRotation = 360;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinRotation = 0;
	
};
