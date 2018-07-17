// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed); //-1 max down movement, 1 is max up movement
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreeperSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
};
