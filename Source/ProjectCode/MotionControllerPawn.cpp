// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionControllerPawn.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "HeadMountedDisplay.h"
#include "MotionControllerComponent.h"
#include "MyPlayer.h"
#include "Engine.h"


// Sets default values
AMotionControllerPawn::AMotionControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRCameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRCameraRoot"));
	RootComponent = VRCameraRoot;
	RootComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(RootComponent);

	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftHand"));
	LeftHand->Hand = EControllerHand::Left;
	LeftHand->AttachTo(RootComponent);

	RightHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightHand"));
	RightHand->Hand = EControllerHand::Right;
	RightHand->AttachTo(RootComponent);



	LeftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftMesh"));
	LeftMesh->AttachTo(LeftHand);

	RightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightMesh"));
	RightMesh->AttachTo(RightHand);

	auto LeftMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/manoMesh"));
	//auto LeftMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Metal_Gold"));
	LeftMesh->SetWorldScale3D(FVector(0.08f, 0.08f, 0.08f));
	LeftHand->AddRelativeLocation(FVector(20.0f,-7.0f, -2.0f));

	auto RightMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/manoMesh"));
	//auto RightMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Metal_Chrome"));
	RightMesh->SetWorldScale3D(FVector(0.08f, -0.08f, 0.08f));
	RightHand->AddRelativeLocation(FVector(20.0f, 7.0f, -2.0f));

	if (LeftMeshAsset.Object != nullptr && RightMeshAsset.Object != nullptr) {
		LeftMesh->SetStaticMesh(LeftMeshAsset.Object);
		//LeftMesh->SetMaterial(0, LeftMeshMaterial.Object);
		RightMesh->SetStaticMesh(RightMeshAsset.Object);
		//RightMesh->SetMaterial(0, RightMeshMaterial.Object);
	}



	

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMotionControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotionControllerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Left Trigger Press
void AMotionControllerPawn::MotionControlLeftTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Left trigger is PRESSED"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Left trigger is PRESSED");
}

// Left Trigger Release
void AMotionControllerPawn::MotionControlLeftTriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Left trigger is RELEASED"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Left trigger is RELEASED");
}

// Right Trigger Press
void AMotionControllerPawn::MotionControlRightTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Right trigger is PRESSED"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Right trigger is PRESSED");
}

// Right Trigger Release
void AMotionControllerPawn::MotionControlRightTriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Right trigger is RELEASED"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Right trigger is RELEASED");
}



// Called to bind functionality to input

void AMotionControllerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	//Motion controller bindings
	InputComponent->BindAction("LeftTrigger", EInputEvent::IE_Pressed, this, &AMotionControllerPawn::MotionControlLeftTriggerPressed);
	InputComponent->BindAction("LeftTrigger", EInputEvent::IE_Released, this, &AMotionControllerPawn::MotionControlLeftTriggerReleased);
	InputComponent->BindAction("RightTrigger", EInputEvent::IE_Pressed, this, &AMotionControllerPawn::MotionControlRightTriggerPressed);
	InputComponent->BindAction("RightTrigger", EInputEvent::IE_Released, this, &AMotionControllerPawn::MotionControlRightTriggerReleased);

}

