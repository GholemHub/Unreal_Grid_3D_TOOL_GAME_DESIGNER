// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Actor12.h"
#include "MyPlayerController12.generated.h"

/**
 * 
 */
UCLASS()
class GRIDTEST_API AMyPlayerController12 : public APlayerController
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
        TArray<AActor12*> CubeActors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
        TArray<AActor12*> SphereActors;
protected:
    virtual void BeginPlay() override;
};
