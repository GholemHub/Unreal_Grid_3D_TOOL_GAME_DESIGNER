// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPair.h"

// Sets default values
AActorPair::AActorPair()
{
    // Create the root scene component
    RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    RootComponent = RootSceneComponent;

    // Create the mesh components for Actor1 and Actor2
    Actor1MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Actor1MeshComponent"));
    Actor2MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Actor2MeshComponent"));

    // Attach the mesh components to the root scene component
    Actor1MeshComponent->SetupAttachment(RootComponent);
    Actor2MeshComponent->SetupAttachment(RootComponent);

    // Set the desired locations for Actor1 and Actor2
    //FVector Actor1Location(0.f, 0.f, 0.f);  // Update the values as per your desired location for Actor1
    //FVector Actor2Location(100.f, 0.f, 0.f);  // Update the values as per your desired location for Actor2

    // Set the locations for Actor1 and Actor2
    Actor1MeshComponent->SetRelativeLocation(Actor1Location);
    Actor2MeshComponent->SetRelativeLocation(Actor2Location);
}


void AActorPair::SetActorLocation(int32 ActorIndex, FVector NewLocation)
{
    if (ActorIndex == 0)
    {
        Actor1Location = NewLocation;
        Actor1MeshComponent->SetRelativeLocation(Actor1Location);
    }
    else if (ActorIndex == 1)
    {
        Actor2Location = NewLocation;
        Actor2MeshComponent->SetRelativeLocation(Actor2Location);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid actor index provided."));
    }
}



