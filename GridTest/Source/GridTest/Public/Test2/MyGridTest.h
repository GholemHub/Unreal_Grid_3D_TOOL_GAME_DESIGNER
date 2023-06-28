// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCellActor.h"
#include "MyGridTest.generated.h"

UCLASS()
class GRIDTEST_API AMyGridTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyGridTest();


    UPROPERTY(EditAnywhere, Category = "Grid")
        int32 GridSizeX;

    UPROPERTY(EditAnywhere, Category = "Grid")
        int32 GridSizeY;
    UPROPERTY(EditAnywhere, Category = "Grid")
        int32 GridSizeZ;

    UPROPERTY(EditAnywhere, Category = "Grid")
        TSubclassOf<AGridCellActor> GridCellClass;

protected:
    virtual void OnConstruction(const FTransform& Transform) override;

private:
    void CreateGrid();
    void ClearGrid();

    TArray<AGridCellActor*> GridCells;
};