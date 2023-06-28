// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor12.generated.h"

UENUM(BlueprintType)
enum class EShapeType : uint8
{
	Cube,
	Sphere
};

UCLASS()
class GRIDTEST_API AActor12 : public AActor
{
	GENERATED_BODY()
public:
	AActor12();
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape")
		TEnumAsByte<EShapeType> ShapeType;

		UStaticMesh* CubeMeshComponent;
		void GetStaticMeshComponent();
protected:
	virtual void OnConstruction(const FTransform& Transform) override;

};
