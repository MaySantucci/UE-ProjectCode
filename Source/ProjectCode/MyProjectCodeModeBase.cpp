// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectCodeModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "TimerManager.h"
#include "MyPlayer.h"
#include "MotionControllerPawn.h"
#include "ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"

AMyProjectCodeModeBase::AMyProjectCodeModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Inizioooo"));
	PlayerControllerClass = AMyPlayer::StaticClass();
	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/MyMotionControllerPawn.MyMotionControllerPawn_C'"));
	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nessun Pawn Trovato"));
	}

	bSpawnEnable = true;
	
}

void AMyProjectCodeModeBase::BeginPlay() 
{
	SetCurrentState(EPlayState::EPlaying);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("BEGIN PLAY"));

	if (bSpawnEnable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Spawn Actors"));
		CreateActorFunction();
		CreateSecondActorFunction();
	}
}

void AMyProjectCodeModeBase::Tick(float DeltaTime) {

	AMotionControllerPawn * MyCharacter = Cast<AMotionControllerPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	if(MyCharacter->TotalGood == 3) {
		SetCurrentState(EPlayState::EEndGame);
	}
}

void AMyProjectCodeModeBase::CreateActorFunction() 
{
	if (bSpawnEnable)
	{
		GetWorldTimerManager().SetTimer(TimeoutStart, this, &AMyProjectCodeModeBase::CreateActorFunction, rand() % 20 + 5);

		float x = rand() % 400 + (-400);
		float y = rand() % 400 + (-400);
		float z = 32.0f;
		FVector NewLocation = FVector(x, y, z);
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		SpawnedFirstActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), NewLocation, FRotator::ZeroRotator, ActorSpawnParameters);

		if (SpawnedFirstActor != nullptr) {
			AllFirstSpawnedActors.Add(SpawnedFirstActor);
		}

		int size = AllFirstSpawnedActors.Num();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::White, FString::Printf(TEXT("Actor Created. Array: %d"), size));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Location. X: %f . y: %f. z: %f."), x, y, z));
	}
}

void AMyProjectCodeModeBase::DestroyActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutEnd, this, &AMyProjectCodeModeBase::DestroyActorFunction, rand() % 40 + 20);
	AMyFirstActor* FirstSpawned = AllFirstSpawnedActors[0];
	if (FirstSpawned != nullptr) {
		FirstSpawned->Destroy();
		AllFirstSpawnedActors.Find(FirstSpawned);
		AllFirstSpawnedActors.RemoveAt(0);
		AllFirstSpawnedActors.Shrink();

		int size = AllFirstSpawnedActors.Num();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Actor Destroy. Array: %d"), size));
	}


}

void AMyProjectCodeModeBase::CreateSecondActorFunction() {
	if (bSpawnEnable)
	{
		GetWorldTimerManager().SetTimer(TimeoutSecondStart, this, &AMyProjectCodeModeBase::CreateSecondActorFunction, rand() % 20 + 5);

		float x = rand() % 400 + (-400);
		float y = rand() % 400 + (-400);
		float z = 32.0f;
		FVector NewLocation = FVector(x, y, z);
		FActorSpawnParameters SecondActorSpawnParameters;
		SecondActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		SpawnedSecondActor = GetWorld()->SpawnActor<AMySecondActor>(AMySecondActor::StaticClass(), NewLocation, FRotator::ZeroRotator, SecondActorSpawnParameters);

		if (SpawnedSecondActor != nullptr) {
			AllSecondSpawnedActors.Add(SpawnedSecondActor);
		}

		int size = AllSecondSpawnedActors.Num();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, FString::Printf(TEXT("SECOND_Actor Created. Array: %d"), size));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("SECOND_Location. X: %f . y: %f. z: %f."), x, y, z));
	}
}

void AMyProjectCodeModeBase::DestroySecondActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutSecondEnd, this, &AMyProjectCodeModeBase::DestroySecondActorFunction, rand() % 40 + 20);
	AMySecondActor* SecondSpawned = AllSecondSpawnedActors[0];
	if (SecondSpawned != nullptr) {
		SecondSpawned->Destroy();
		AllSecondSpawnedActors.Find(SecondSpawned);
		AllSecondSpawnedActors.RemoveAt(0);
		AllSecondSpawnedActors.Shrink();

		int size = AllSecondSpawnedActors.Num();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("SECOND_Actor Destroy. Array: %d"), size));
	}


}

EPlayState AMyProjectCodeModeBase::GetCurrentState() const {
	return CurrentState;
}

void AMyProjectCodeModeBase::SetCurrentState(EPlayState NewState) {
	CurrentState = NewState;
	HandleNewState(NewState);
}


void AMyProjectCodeModeBase::CreateHUD() {
	FVector NewLocation = FVector(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters HUDSpawnParameters;
	HUDSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	ScoreHUD = GetWorld()->SpawnActor<AScore_HUD>(AScore_HUD::StaticClass(), NewLocation, FRotator::ZeroRotator, HUDSpawnParameters);

}

void AMyProjectCodeModeBase::HandleNewState(EPlayState NewState) {
	
	switch (NewState) {
	case EPlayState::EIntro:
		break;
	case EPlayState::EPlaying:
		CreateHUD();
		break;
	case EPlayState::EEndGame:
		bSpawnEnable = false;
		UE_LOG(LogTemp, Warning, TEXT("Fine Gioco"));

		AMotionControllerPawn * MyCharacter = Cast<AMotionControllerPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		MyCharacter->DisableInput(PlayerController);
		break;
	}
}