// Fill out your copyright notice in the Description page of Project Settings.


#include "EditableArray.h"

// Sets default values
AEditableArray::AEditableArray()
{
    int32 SizeX = 2;
    int32 SizeY = 2;
    int32 SizeZ = 2;
    My3DArray.SetNum(SizeX);

    UWorld* World = GetWorld();
    if (World)
    {
        for (int32 X = 0; X < SizeX; ++X)
        {
            My3DArray[X].ArrayOfInts.SetNum(SizeY);

            for (int32 Y = 0; Y < SizeY; ++Y)
            {
                My3DArray[X].ArrayOfInts[Y].ArrayOfInts.SetNum(SizeZ);

                for (int32 Z = 0; Z < SizeZ; ++Z)
                {
                    FVector SpawnLocation = FVector(Z * 10.0f, X * 10.0f, Y * 10.0f);
                    FRotator SpawnRotation = FRotator::ZeroRotator;
                    FActorSpawnParameters SpawnParams;
                    // Spawn a new actor of the specified blueprint class and add it to the 3D array
                    AActor* NewActor = World->SpawnActor<AActor>(Element, SpawnLocation, SpawnRotation, SpawnParams);
                    My3DArray[X].ArrayOfInts[Y].ArrayOfInts[Z] = NewActor;
                    NewActor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

                    //RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
                    //RootComponent = RootSceneComponent;

                    // Create the mesh components for Actor1 and Actor2
                    Actor1MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Actor1MeshComponent"));
                  
                    // Attach the mesh components to the root scene component
                    Actor1MeshComponent->SetupAttachment(RootComponent);
                }
            }
        }
    }
}
