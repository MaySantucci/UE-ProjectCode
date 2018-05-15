// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstActor.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"
#include "Engine.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));

	auto MyMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	auto MyMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Wood_Pine"));


	if (MyMeshAsset.Object != nullptr) {
		MyMesh->SetStaticMesh(MyMeshAsset.Object);
		MyMesh->SetMaterial(0, MyMeshMaterial.Object);
	}

	MyMesh->SetMobility(EComponentMobility::Movable);
	MyMesh->SetSimulatePhysics(true);

	MyMesh->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	
	//MyMesh->OnComponentBeginOverlap.AddDynamic(this, &AMyFirstActor::OnOverlapBegin);
	//auto AutoPossessPlayer = EAutoReceiveInput::Player1;
}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyFirstActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
		OverlappedComp->SetVisibility(false);
	}
}

