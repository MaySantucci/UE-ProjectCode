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

		float x = rand() % 400 + (-400);
		float y = rand() % 400 + (-400);
		float z = 32.0f;
		FVector NewLocation = FVector(x, y, z);
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), NewLocation, FRotator::ZeroRotator, ActorSpawnParameters);
		
		if (SpawnedActor != nullptr) {
			AllSpawnedActors.Add(SpawnedActor);
		}
		
		int size = AllSpawnedActors.Num();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::White, FString::Printf(TEXT("Actor Created. Array: %d"), size));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Location. X: %f . y: %f. z: %f."), x, y, z));
}

void AMyProjectCodeModeBase::DestroyActorFunction() {

	GetWorldTimerManager().SetTimer(TimeoutEnd, this, &AMyProjectCodeModeBase::DestroyActorFunction, rand() % 40 + 20);
	AMyFirstActor* FirstSpawned = AllSpawnedActors[0];
		if (FirstSpawned != nullptr) {
			FirstSpawned->Destroy();
			AllSpawnedActors.Find(FirstSpawned);
			AllSpawnedActors.RemoveAt(0);
			AllSpawnedActors.Shrink();	

			int size = AllSpawnedActors.Num();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Actor Destroy. Array: %d"), size));
	}
		

}

