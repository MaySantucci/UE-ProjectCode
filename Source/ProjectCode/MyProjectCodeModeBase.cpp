// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectCodeModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "TimerManager.h"


void AMyProjectCodeModeBase::BeginPlay() {
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));
	FVector NewLocation = FVector(0.f, 0.f, 320.f);
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), NewLocation, FRotator::ZeroRotator);

	GetWorldTimerManager().SetTimer(Timer, this, &AMyProjectCodeModeBase::DestroyActorFunction, 10);
}

void AMyProjectCodeModeBase::DestroyActorFunction() {
	if (SpawnedActor != nullptr) {
		SpawnedActor->Destroy();
	}
}

