// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "MySecondActor.h"
#include "IntroHUD.h"
#include "Score_HUD.h"
#include "End_HUD.h"
#include "MyProjectCodeModeBase.generated.h"

enum class EPlayState : short {
	EIntro,
	EPlaying,
	EEndGame
};

UCLASS()
class PROJECTCODE_API AMyProjectCodeModeBase : public AGameModeBase
{
	GENERATED_BODY()

		
public:
	AMyProjectCodeModeBase();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		AMyFirstActor* SpawnedFirstActor;

	UPROPERTY()
		AMySecondActor* SpawnedSecondActor;

	UPROPERTY()
		AIntroHUD* IntroHUD;
	UPROPERTY()
		AScore_HUD* ScoreHUD;
	UPROPERTY()
		AEnd_HUD* EndHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AMyFirstActor*> AllFirstSpawnedActors;

	UPROPERTY()
		TArray<AMySecondActor*> AllSecondSpawnedActors;

	int32 cont;

	UFUNCTION()
		void DestroyActorFunction();
	UFUNCTION()
		void CreateActorFunction();

	UFUNCTION()
		void CreateIntroHUD();
	UFUNCTION()
		void CreateScoreHUD();
	UFUNCTION()
		void CreateEndHUD();
	UFUNCTION()
		void DestroyIntroHUD();
	UFUNCTION()
		void DestroyScoreHUD();
	UFUNCTION()
		void DestroyEndHUD();


	UFUNCTION()
		void DestroySecondActorFunction();
	UFUNCTION()
		void CreateSecondActorFunction();

	FTimerHandle TimeoutStart;
	FTimerHandle TimeoutEnd;
	FTimerHandle TimeoutSecondStart;
	FTimerHandle TimeoutSecondEnd;

	EPlayState GetCurrentState() const;
	void SetCurrentState(EPlayState NewState);
	
private:
	EPlayState CurrentState;
	void HandleNewState(EPlayState NewState);
	bool bSpawnEnable;

};
