// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Runtime/Engine/Classes/Components/StereoLayerComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WidgetScore")
		UStereoLayerComponent* StereoLayer;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WidgetScore")
		UWidgetComponent* Widget;

/*
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UStaticMeshComponent* Button;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UBoxComponent* CollisionBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ButtonWidget")
		UTextRenderComponent* PlayText;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
*/
};
