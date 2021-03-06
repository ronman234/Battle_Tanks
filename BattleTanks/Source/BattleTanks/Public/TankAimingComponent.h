// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

class UTankBarrel; 
class UTankTurretComponent;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

	bool IsBarrelMoving();

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurretComponent* TurretToSet);
	
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable)
	void Fire();

	EFiringState GetFiringState() const;

protected:
	UTankBarrel* Barrel = nullptr;

	UTankTurretComponent* Turret = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(BlueprintReadOnly, Category = Setup)
	EFiringState FiringStatus = EFiringState::Reloading;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3;

	UFUNCTION(BlueprintCallable, Category = Firing)
	int32 GetRoundsLeft() const;

	float LastFireTime = 0;

	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		int32 RoundsLeft = 20;

};
