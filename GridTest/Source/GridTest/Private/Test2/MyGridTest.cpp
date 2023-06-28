// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2/MyGridTest.h"


AMyGridTest::AMyGridTest()
{
    // Set up the default grid size
    GridSizeX = 2;
    GridSizeY = 2;
    GridSizeZ = 2;

    // Set the default grid cell class
    GridCellClass = AGridCellActor::StaticClass();

    // Create the initial grid
    CreateGrid();
}

void AMyGridTest::OnConstruction(const FTransform& Transform)
{
    // Clear the existing grid cells
    ClearGrid();

    // Recreate the grid based on the updated size
    CreateGrid();

    // Call the parent's OnConstruction function
    Super::OnConstruction(Transform);
}

void AMyGridTest::CreateGrid()
{
    // Loop through the grid size and create grid cells
    
    for (int32 X = 0; X < GridSizeX; X++)
    {
        for (int32 Y = 0; Y < GridSizeY; Y++)
        {
            for (int32 Z = 0; Z < GridSizeZ; Z++)
            {
                // Create a new grid cell actor
                UWorld* World = GetWorld();
                if (World)
                {
                    AGridCellActor* GridCell = World->SpawnActor<AGridCellActor>(GridCellClass);

                    // Calculate the position offset
                    FVector Offset(X * 200.0f, Y * 200.0f, Z * 200.0f);

                    // Set the position of the grid cell
                    FVector CellPosition = GetActorLocation() + Offset;
                    GridCell->SetActorLocation(CellPosition);

                    // Add the grid cell actor to the grid
                    GridCells.Add(GridCell);
                }
            }
        }
    }
}

void AMyGridTest::ClearGrid()
{
    // Destroy all existing grid cell actors
    if (GridCells.Num() != 0)
    {
        for (AGridCellActor* GridCell : GridCells)
        {
            if (GridCell)
            {
                GridCell->Destroy();
            }
        }
    }
    
    // Clear the grid cells array
    GridCells.Empty();
}