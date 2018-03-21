// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstActor.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));

	auto MyMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	auto MyMeshMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Wood_Pine"));


	if (MyMeshAsset.Object != nullptr) {
		MyMesh->SetStaticMesh(MyMeshAsset.Object);
		MyMesh->SetMaterial(0, MyMeshMaterial.Object);
	}
		
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

