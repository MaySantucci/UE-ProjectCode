// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MotionControllerPawn.generated.h"

UCLASS()
class PROJECTCODE_API AMotionControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMotionControllerPawn();

	UPROPERTY()
		USceneComponent* VROrigin;
	UPROPERTY()
		UCameraComponent* Camera;
	UPROPERTY()
		UMotionControllerComponent* LeftHand;
	UPROPERTY()
		UMotionControllerComponent* RightHand;
	UPROPERTY()
		USkeletalMeshComponent* LeftMesh;
	UPROPERTY()
		USkeletalMeshComponent* RightMesh;
	UPROPERTY()
		FName DeviceName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetupVROptions();

	/* Resets HMD Origin position and orientation */
	void ResetHMDOrigin();

	UFUNCTION()
		virtual void MotionControlLeftTriggerPressed();

	UFUNCTION()
		virtual void MotionControlLeftTriggerReleased();

	UFUNCTION()
		virtual void MotionControlRightTriggerPressed();

	UFUNCTION()
		virtual void MotionControlRightTriggerReleased();

	
};
