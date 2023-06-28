// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeometryObjects.generated.h"

UENUM(BlueprintType)
enum class EGeometrySelection1 : uint8
{
	Sphere,
	Cube,
	Cylinder
};

UCLASS()
class GRIDTEST_API AGeometryObjects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeometryObjects();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry")
		EGeometrySelection1 SelectedGeometry;
	

protected:

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	void UpdateConstructor();

private:
	UStaticMeshComponent* MeshComponent;


};
