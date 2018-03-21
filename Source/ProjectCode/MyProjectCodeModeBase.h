// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "MyProjectCodeModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCODE_API AMyProjectCodeModeBase : public AGameModeBase
{
	GENERATED_BODY()

		
public:
	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnedActor;
	UPROPERTY(VisibleAnywhere, Category="Comps")
		TArray<AMyFirstActor*> AllSpawnedActors;

	int32 cont;

	UFUNCTION()
		void DestroyActorFunction();
	UFUNCTION()
		void CreateActorFunction();

	FTimerHandle TimeoutStart;
	FTimerHandle TimeoutEnd;
};
