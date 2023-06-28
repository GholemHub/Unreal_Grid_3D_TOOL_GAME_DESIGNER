// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/GeometryHubActors.h"
#include "Engine/World.h"


// Sets default values
AGeometryHubActors::AGeometryHubActors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
    UWorld* World = GetWorld();
    if (World)
    {
        FVector SpawnLocation(0.f, 0.f, 0.f);  // Set the desired default location
        FRotator SpawnRotation(0.f, 0.f, 0.f);  // Set the desired default rotation
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AActor* SpawnedActor = World->SpawnActor<ASimplMesh>(GeometryClass, SpawnLocation, SpawnRotation, SpawnParams);

        if (SpawnedActor)
        {
            FVector SpawnScale(1.f, 1.f, 1.f);  // Set the desired default scale
            SpawnedActor->SetActorScale3D(SpawnScale);
        }
    }
	
}

// Called when the game starts or when spawned
void AGeometryHubActors::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AGeometryHubActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

