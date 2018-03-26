// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionControllerPawn.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "HeadMountedDisplay.h"
#include "MotionControllerComponent.h"


// Sets default values
AMotionControllerPawn::AMotionControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRCameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRCameraRoot"));
	RootComponent = VRCameraRoot;

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

	auto LeftMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	auto LeftMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Metal_Gold"));
	LeftMesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	LeftHand->AddRelativeLocation(FVector(0.0f,20.0f, -2.0f));

	auto RightMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	auto RightMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Metal_Chrome"));
	RightMesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	RightHand->AddRelativeLocation(FVector(0.0f, -20.0f, -2.0f));

	if (LeftMeshAsset.Object != nullptr && RightMeshAsset.Object != nullptr) {
		LeftMesh->SetStaticMesh(LeftMeshAsset.Object);
		LeftMesh->SetMaterial(0, LeftMeshMaterial.Object);
		RightMesh->SetStaticMesh(RightMeshAsset.Object);
		RightMesh->SetMaterial(0, RightMeshMaterial.Object);
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

// Called to bind functionality to input
void AMotionControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

