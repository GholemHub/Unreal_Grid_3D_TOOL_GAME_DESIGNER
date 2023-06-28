// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test/SimplMesh.h"
#include "GeometryHubActors.generated.h"

UCLASS()
class GRIDTEST_API AGeometryHubActors : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeometryHubActors();

protected:
	UPROPERTY(EditAnywhere, Category="Geometry")
		TSubclassOf<ASimplMesh> GeometryClass;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
