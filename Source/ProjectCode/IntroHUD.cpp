// Fill out your copyright notice in the Description page of Project Settings.

#include "IntroHUD.h"
#include "ConstructorHelpers.h"

// Sets default values
AIntroHUD::AIntroHUD()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayButton"));
	Button->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Button->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Button->SetWorldScale3D(FVector(1.0f, 0.2f, 1.0));

	auto ButtonAssets = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ButtonAssets.Object != nullptr) {
		Button->SetStaticMesh(ButtonAssets.Object);
	}

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayBox"));
	CollisionBox->AttachToComponent(Button, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	CollisionBox->SetWorldScale3D(FVector(1.5f, 0.4f, 1.5f));

	PlayText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PlayText"));
	PlayText->AttachToComponent(CollisionBox, FAttachmentTransformRules::KeepRelativeTransform);
	PlayText->SetRelativeLocation(FVector(-30.0f, 30.0f, -1.0f));
	PlayText->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	PlayText->SetTextRenderColor(FColor::Black);
	PlayText->SetText(TEXT("PLAY"));
	PlayText->SetWorldScale3D(FVector(1.0f, 1.5f, 1.0f));

}

// Called when the game starts or when spawned
void AIntroHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIntroHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

