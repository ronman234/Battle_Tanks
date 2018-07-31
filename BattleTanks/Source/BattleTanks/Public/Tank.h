// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurretComponent;
class AProjectile;
class UTankTrack;
class UTankMovementComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurretComponent* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();	

protected:
	UTankBarrel* Barrel = nullptr; // local barrel reference

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3;
	
	float LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;
};
