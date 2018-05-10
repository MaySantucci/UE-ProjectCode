// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstActor.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"

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

