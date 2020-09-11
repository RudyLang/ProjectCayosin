// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ARPGCharacter.generated.h"

class AGunActor; // Forward Declare

UCLASS()
class CAYOSIN_API AARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARPGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

public:
	UPROPERTY(EditAnywhere)
		float RotationRate = 10.0f;

	UPROPERTY(EditDefaultsOnly) // Don't edit it at runtime
		TSubclassOf<AGunActor> GunClass; // Only allow subclass of GunActor

	UPROPERTY()
		AGunActor* Gun;
};
