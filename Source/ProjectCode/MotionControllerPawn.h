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
#include "Runtime/Engine/Classes/Components/StereoLayerComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "MotionControllerPawn.generated.h"

/* 
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class GripEnum : uint8
{
	Open 	UMETA(DisplayName = "Open"),
	CanGrab	UMETA(DisplayName = "CanGrab"),
	Grab 	UMETA(DisplayName = "Grab")
};
*/

UCLASS()
class PROJECTCODE_API AMotionControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMotionControllerPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		USceneComponent* VROrigin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		UCameraComponent* Camera;
/*
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "StereoLayer")
		UStereoLayerComponent* StereoLayer;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "StereoLayer")
		UWidgetComponent* Widget;
*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		UMotionControllerComponent* LeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		UMotionControllerComponent* RightHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		USkeletalMeshComponent* LeftMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		USkeletalMeshComponent* RightMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotionController")
		FName DeviceName;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
		int TotalGood;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
		int TotalBad;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MotionController")
		bool bWantsToGrip_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MotionController")
		bool bWantsToGrip_R;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		//GripEnum GripState;
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

	
	UFUNCTION(BlueprintCallable)
		virtual void MotionControlLeftTriggerPressed();

	UFUNCTION(BlueprintCallable)
		virtual void MotionControlLeftTriggerReleased();

	UFUNCTION(BlueprintCallable)
		virtual void MotionControlRightTriggerPressed();

	UFUNCTION(BlueprintCallable)
		virtual void MotionControlRightTriggerReleased();

	
	
};
