// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "IntroHUD.generated.h"

UCLASS()
class PROJECTCODE_API AIntroHUD : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIntroHUD();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UStaticMeshComponent* Button;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UBoxComponent* CollisionBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UTextRenderComponent* PlayText;

	
};
