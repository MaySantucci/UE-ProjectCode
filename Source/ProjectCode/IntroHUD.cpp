// Fill out your copyright notice in the Description page of Project Settings.

#include "IntroHUD.h"
#include "ConstructorHelpers.h"
#include "Engine.h"

// Sets default values
AIntroHUD::AIntroHUD()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	StereoLayer = CreateDefaultSubobject<UStereoLayerComponent>(TEXT("StereoLayer"));
	StereoLayer->SetRelativeLocation(FVector(400.0f, 0.0f, 0.0f));

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetRelativeLocation(FVector(0.0f, 0.0f, 240.0f));
	Widget->SetWorldScale3D(FVector(-1.0, -1.0f, 1.0f));
	Widget->AttachTo(StereoLayer);

	auto IntroAsset = ConstructorHelpers::FObjectFinder<UClass>(TEXT("WidgetBlueprint'/Game/UMG/Intro_UMG.Intro_UMG_C'"));
	if (IntroAsset.Object != nullptr) {
		Widget->SetWidgetClass(IntroAsset.Object);
	}
	/*
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
	PlayText->AttachToComponent(Button, FAttachmentTransformRules::KeepRelativeTransform);
	PlayText->SetRelativeLocation(FVector(-40.0f, 60.0f, 35.0f));
	PlayText->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	PlayText->SetTextRenderColor(FColor::Black);

	FText TestHUDText = FText::FromString(TEXT("PLAY"));
	PlayText->SetText(TestHUDText);
	PlayText->SetWorldScale3D(FVector(1.0f, 1.5f, 1.0f));


	Button->OnComponentHit.AddDynamic(this, &AIntroHUD::OnHit);
	Button->OnComponentBeginOverlap.AddDynamic(this, &AIntroHUD::OnOverlapBegin);
	*/

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
/*
void AIntroHUD::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Componente urtata!"));
}

void AIntroHUD::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		UE_LOG(LogTemp, Error, TEXT("Overlap Begin"));
	}
}
*/