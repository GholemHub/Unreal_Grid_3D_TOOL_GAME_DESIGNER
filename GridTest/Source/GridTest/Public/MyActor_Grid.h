// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor_Grid.generated.h"

UCLASS()
class GRIDTEST_API AMyActor_Grid : public AActor
{
	GENERATED_BODY()
	
public:
    AMyActor_Grid();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, Category = "Grid")
        float Spacing;

    UPROPERTY(EditAnywhere, Category = "Grid")
        TArray<UStaticMesh*> Meshes;

};
