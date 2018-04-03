// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "MySecondActor.h"
#include "MyProjectCodeModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCODE_API AMyProjectCodeModeBase : public AGameModeBase
{
	GENERATED_BODY()

		
public:
	AMyProjectCodeModeBase();
	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnedFirstActor;
	UPROPERTY()
		AMySecondActor* SpawnedSecondActor;
	UPROPERTY()
		TArray<AMyFirstActor*> AllFirstSpawnedActors;
	UPROPERTY()
		TArray<AMySecondActor*> AllSecondSpawnedActors;

	int32 cont;

	UFUNCTION()
		void DestroyActorFunction();
	UFUNCTION()
		void CreateActorFunction();
	UFUNCTION()
		void DestroySecondActorFunction();
	UFUNCTION()
		void CreateSecondActorFunction();

	FTimerHandle TimeoutStart;
	FTimerHandle TimeoutEnd;
	FTimerHandle TimeoutSecondStart;
	FTimerHandle TimeoutSecondEnd;
};
