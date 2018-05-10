// Fill out your copyright notice in the Description page of Project Settings.

#include "MySecondActor.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"


// Sets default values
AMySecondActor::AMySecondActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyBadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyBadMesh"));
	MyBadMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));

	auto MyBadMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	auto MyBadMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Wood_Walnut"));

	if (MyBadMeshAsset.Object != nullptr) {
		MyBadMesh->SetStaticMesh(MyBadMeshAsset.Object);
		MyBadMesh->SetMaterial(0, MyBadMeshMaterial.Object);
	}


	MyBadMesh->SetMobility(EComponentMobility::Movable);
	MyBadMesh->SetSimulatePhysics(true);

	MyBadMesh->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	//auto AutoPossessPlayer = EAutoReceiveInput::Player1;
}

// Called when the game starts or when spawned
void AMySecondActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySecondActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

