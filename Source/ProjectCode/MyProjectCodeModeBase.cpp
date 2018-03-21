// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectCodeModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "TimerManager.h"

void AMyProjectCodeModeBase::BeginPlay() {

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Actor Spawning"));
	CreateActorFunction();
	DestroyActorFunction();

}

void AMyProjectCodeModeBase::CreateActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutStart, this, &AMyProjectCodeModeBase::CreateActorFunction, rand() % 20 + 5);

		float x = rand() % 200 + (-200);
		float y = rand() % 200 + (-200);
		float z = 32.0f;
		FVector NewLocation = FVector(x, y, z);
		SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), NewLocation, FRotator::ZeroRotator);

		if (SpawnedActor != nullptr) {
			AllSpawnedActors.Add(SpawnedActor);
		}
		
		int size = AllSpawnedActors.Num();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::White, FString::Printf(TEXT("Actor Created. Array: %d"), size));
}

void AMyProjectCodeModeBase::DestroyActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutEnd, this, &AMyProjectCodeModeBase::DestroyActorFunction, rand() % 40 + 20);
		if (SpawnedActor != nullptr) {
			AllSpawnedActors.RemoveAt(0);
			SpawnedActor->Destroy();

			int size = AllSpawnedActors.Num();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Actor Destroy. Array: %d"), size));
	}
		

}

