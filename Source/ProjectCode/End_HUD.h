// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StereoLayerComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "End_HUD.generated.h"

UCLASS()
class PROJECTCODE_API AEnd_HUD : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnd_HUD();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WidgetScore")
		USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WidgetScore")
		UStereoLayerComponent* StereoLayer;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WidgetScore")
		UWidgetComponent* Widget;
	
	
};
