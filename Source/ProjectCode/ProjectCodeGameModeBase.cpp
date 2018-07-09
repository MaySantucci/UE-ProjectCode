// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectCodeGameModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "MyPlayer.h"
#include "MotionControllerPawn.h"
#include "ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AProjectCodeGameModeBase::AProjectCodeGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Inizio NewMapLevel"));
	if (AMyPlayer::StaticClass() != nullptr)
	{
		PlayerControllerClass = AMyPlayer::StaticClass();
	}

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/MyMotionControllerPawn.MyMotionControllerPawn_C'"));
	if (PlayerPawnObject.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nessun Pawn Trovato"));
	}

}
