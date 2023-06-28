// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCellActor.generated.h"

UENUM(BlueprintType)
enum class EGeometrySelection : uint8
{
    Wall UMETA(DisplayName = "Wall"),
    Coin UMETA(DisplayName = "Coin"),
    Air UMETA(DisplayName = "Air"),
};

UCLASS()
class GRIDTEST_API AGridCellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridCellActor();


#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    virtual void BeginPlay() override;

protected:
    void SetMeshBasedOnSelection();

    UPROPERTY(VisibleAnywhere, Category = "Components")
        UStaticMeshComponent* CellMesh;

    UPROPERTY(EditAnywhere, Category = "Change Mesh")
        EGeometrySelection MeshSelection;

    UPROPERTY()
        UStaticMesh* Air;

    UPROPERTY()
        UStaticMesh* Wall;

    UPROPERTY()
        UStaticMesh* Coin;

    TMap<EGeometrySelection, UStaticMesh*> Meshes;

    EGeometrySelection CurrentMeshSelection;
};
