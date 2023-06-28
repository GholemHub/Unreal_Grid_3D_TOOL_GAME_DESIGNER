// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2/GridCellActor.h"
#include "Engine/StaticMesh.h"
// Sets default values
AGridCellActor::AGridCellActor()
{
    CellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CellMesh"));
    RootComponent = CellMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> AirMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/Air_Brush_StaticMesh.Air_Brush_StaticMesh'"));
    if (AirMeshAsset.Succeeded())
    {
        Meshes.Add(EGeometrySelection::Air, AirMeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UStaticMesh> WallMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/Wall_Brush_StaticMesh.Wall_Brush_StaticMesh'"));
    if (WallMeshAsset.Succeeded())
    {
        Meshes.Add(EGeometrySelection::Wall, WallMeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CoinMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/Coin_Brush_StaticMesh.Coin_Brush_StaticMesh'"));
    if (CoinMeshAsset.Succeeded())
    {
        Meshes.Add(EGeometrySelection::Coin, CoinMeshAsset.Object);
    }

    // Load the sphere mesh as the default
    if (Meshes.Contains(EGeometrySelection::Wall))
    {
        CellMesh->SetStaticMesh(Meshes[EGeometrySelection::Wall]);
        CurrentMeshSelection = EGeometrySelection::Wall;
    }
}

#if WITH_EDITOR
void AGridCellActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // Check if the property that changed is the MeshSelection property
    const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGridCellActor, MeshSelection))
    {
        // Update the mesh based on the selected enum value
        if (Meshes.Contains(MeshSelection))
        {
            CellMesh->SetStaticMesh(Meshes[MeshSelection]);
            CurrentMeshSelection = MeshSelection;
            SetMeshBasedOnSelection();
        }
    }
}
#endif

void AGridCellActor::BeginPlay()
{
    Super::BeginPlay();

    // Set the initial mesh based on the selected MeshSelection
    SetMeshBasedOnSelection();
}

void AGridCellActor::SetMeshBasedOnSelection()
{
    UStaticMesh* NewMesh = nullptr;

    switch (MeshSelection)
    {

    case EGeometrySelection::Air:
        NewMesh = Air;
        break;
    case EGeometrySelection::Wall:
        NewMesh = Wall;
        break;
    case EGeometrySelection::Coin:
        NewMesh = Coin;
        break;

    default:
        break;
    }

    // Set the new mesh if it's valid
    if (NewMesh)
    {
        CellMesh->SetStaticMesh(NewMesh);
    }
}