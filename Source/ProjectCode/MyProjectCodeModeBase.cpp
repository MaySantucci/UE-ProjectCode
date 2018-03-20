// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectCodeModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "TimerManager.h"

void AMyProjectCodeModeBase::BeginPlay() {
	CreateActorFunction();
	DestroyActorFunction();

}

void AMyProjectCodeModeBase::CreateActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutStart, this, &AMyProjectCodeModeBase::CreateActorFunction, rand() % 20 + 5);
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));

		float x = rand() % 200 + (-200);
		float y = rand() % 200 + (-200);
		float z = 32.0f;
		FVector NewLocation = FVector(x, y, z);
		SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), NewLocation, FRotator::ZeroRotator);

		if (SpawnedActor != nullptr) {
			AllSpawnedActors.Add(SpawnedActor);
		}
				
}

void AMyProjectCodeModeBase::DestroyActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutEnd, this, &AMyProjectCodeModeBase::DestroyActorFunction, rand() % 40 + 20);
		if (SpawnedActor != nullptr) {
			AllSpawnedActors.RemoveAt(0);
			AllSpawnedActors.Shrink();
			SpawnedActor->Destroy();
	}
		

}

