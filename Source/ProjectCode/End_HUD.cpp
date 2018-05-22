// Fill out your copyright notice in the Description page of Project Settings.

#include "End_HUD.h"
#include "ConstructorHelpers.h"

// Sets default values
AEnd_HUD::AEnd_HUD()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	StereoLayer = CreateDefaultSubobject<UStereoLayerComponent>(TEXT("StereoLayer"));
	StereoLayer->SetRelativeLocation(FVector(400.0f, 0.0f, 0.0f));

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	Widget->SetWorldScale3D(FVector(-1.0, -1.0f, 1.0f));
	Widget->AttachTo(StereoLayer);

	auto ScoreAsset = ConstructorHelpers::FObjectFinder<UClass>(TEXT("WidgetBlueprint'/Game/UMG/End_UMG.End_UMG_C'"));
	if (ScoreAsset.Object != nullptr) {
		Widget->SetWidgetClass(ScoreAsset.Object);
	}
}

// Called when the game starts or when spawned
void AEnd_HUD::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnd_HUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

