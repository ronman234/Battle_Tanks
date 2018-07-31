// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;  }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

//Get world location of linetreace throufh crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	//De-porjection
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//line trace along look direction, and see what we hit
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	//de-project the screen position of crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}

	OutHitLocation = FVector(0.0f);
	return false;
}

