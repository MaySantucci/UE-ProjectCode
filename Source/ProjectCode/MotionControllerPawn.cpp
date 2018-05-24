// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionControllerPawn.h"
#include "ConstructorHelpers.h"
#include "HeadMountedDisplay.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "MotionControllerComponent.h"
#include "MyPlayer.h"
#include "Engine.h"


// Sets default values
AMotionControllerPawn::AMotionControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	RootComponent = VROrigin;
	RootComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	
	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftHand"));
	LeftHand->Hand = EControllerHand::Left;
	LeftHand->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	RightHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightHand"));
	RightHand->Hand = EControllerHand::Right;
	RightHand->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);



	LeftMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftMesh"));
	LeftMesh->SetWorldScale3D(FVector(1.0, -1.0, 1.0));
	LeftMesh->AttachToComponent(LeftHand, FAttachmentTransformRules::KeepWorldTransform);

	auto LeftMeshAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/VirtualReality/Mannequin/Character/Mesh/MannequinHand_Right.MannequinHand_Right'"));
	auto LeftMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/VirtualReality/Mannequin/Character/Materials/M_HandMat.M_HandMat'"));
	auto LeftMeshAnimation = ConstructorHelpers::FObjectFinder<UClass>(TEXT("AnimBlueprint'/Game/VirtualReality/Mannequin/Animations/RightHand_AnimBP.RightHand_AnimBP_C'"));
	if (LeftMeshAsset.Object != nullptr) {
		LeftMesh->SetSkeletalMesh(LeftMeshAsset.Object);
	}

	if (LeftMeshMaterial.Object != nullptr) {
		LeftMesh->SetMaterial(0, LeftMeshMaterial.Object);
	}

	if (LeftMeshAnimation.Object != nullptr) {
		LeftMesh->SetAnimInstanceClass(LeftMeshAnimation.Object);
	}

	LeftHand->SetWorldScale3D(FVector(1.0, 1.0, 1.0));
	LeftHand->SetRelativeRotation(FRotator(0.0, 0.0, -90.0));
	LeftHand->SetRelativeLocation(FVector(10.0, -10.0, 0.0));

	LeftWidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("LeftWidgetInteraction"));
	LeftWidgetInteraction->AttachToComponent(LeftHand, FAttachmentTransformRules::KeepRelativeTransform);

	RightMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightMesh"));
	RightMesh->AttachToComponent(RightHand, FAttachmentTransformRules::KeepWorldTransform);

	
	auto RightMeshAsset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/VirtualReality/Mannequin/Character/Mesh/MannequinHand_Right.MannequinHand_Right'"));
	auto RightMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/VirtualReality/Mannequin/Character/Materials/M_HandMat.M_HandMat'"));
	auto RightMeshAnimation = ConstructorHelpers::FObjectFinder<UClass>(TEXT("AnimBlueprint'/Game/VirtualReality/Mannequin/Animations/RightHand_AnimBP.RightHand_AnimBP_C'"));
	if (RightMeshAsset.Object != nullptr) {
		RightMesh->SetSkeletalMesh(RightMeshAsset.Object);
	}

	if (RightMeshMaterial.Object != nullptr) {
		RightMesh->SetMaterial(0, RightMeshMaterial.Object);
	}

	if (RightMeshAnimation.Object != nullptr) {
		RightMesh->SetAnimInstanceClass(RightMeshAnimation.Object);
	}
	

	RightWidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("RightWidgetInteraction"));
	RightWidgetInteraction->AttachToComponent(RightHand, FAttachmentTransformRules::KeepRelativeTransform);

	RightHand->SetWorldScale3D(FVector(1.0, 1.0, 1.0));
	RightHand->SetRelativeRotation(FRotator(0.0, 0.0, 90.0));
	RightHand->SetRelativeLocation(FVector(10.0, 10.0, 0.0));
}

// Called when the game starts or when spawned
void AMotionControllerPawn::BeginPlay()
{
	Super::BeginPlay();

	DeviceName = UHeadMountedDisplayFunctionLibrary::GetHMDDeviceName();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DeviceName.ToString());
	// NESSUN DEVICE
	if (DeviceName.ToString().Equals("None")) {

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, DeviceName.ToString());
		UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);
	}

	//STEAM VR
	else if (DeviceName.ToString().Equals("SteamVR")) {

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, DeviceName.ToString());
		UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);
		VROrigin->AddLocalOffset(FVector(0.0f, 0.0f, -105.0f));
	}
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

	InputComponent->BindAction("LeftTrigger", EInputEvent::IE_Pressed, this, &AMotionControllerPawn::MotionControlLeftTriggerPressed);
	InputComponent->BindAction("LeftTrigger", EInputEvent::IE_Released, this, &AMotionControllerPawn::MotionControlLeftTriggerReleased);
	InputComponent->BindAction("RightTrigger", EInputEvent::IE_Pressed, this, &AMotionControllerPawn::MotionControlRightTriggerPressed);
	InputComponent->BindAction("RightTrigger", EInputEvent::IE_Released, this, &AMotionControllerPawn::MotionControlRightTriggerReleased);
}

