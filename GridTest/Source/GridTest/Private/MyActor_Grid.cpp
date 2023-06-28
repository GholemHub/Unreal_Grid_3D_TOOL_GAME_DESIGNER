// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_Grid.h"
#include "MyActor_GridSlot.h"

// Sets default values
AMyActor_Grid::AMyActor_Grid()
{
    PrimaryActorTick.bCanEverTick = false;
    Spacing = 100.f; // Adjust the spacing as needed

}

// Called when the game starts or when spawned
void AMyActor_Grid::BeginPlay()
{
    Super::BeginPlay();

    int32 NumMeshes = Meshes.Num();
    int32 Index = 0;

    // Calculate the total size of the grid
    FVector GridSize = FVector(3, 3, 1) * Spacing;

    // Calculate the starting point of the grid
    FVector StartLocation = GetActorLocation() - (GridSize / 2.f);

    // Create the grid of meshes
    for (int32 Row = 0; Row < 3; ++Row)
    {
        for (int32 Column = 0; Column < 3; ++Column)
        {
            // Create a static mesh component
            UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this);
            MeshComponent->SetStaticMesh(Meshes[Index]);

            // Set the location of the mesh in the grid
            FVector Location = StartLocation + FVector(Column, Row, 0) * Spacing;
            MeshComponent->SetRelativeLocation(Location);

            // Attach the mesh component to the actor
            MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

            // Increment the index
            Index = (Index + 1) % NumMeshes;
        }
    }
	
}
