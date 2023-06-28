#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimplMesh.generated.h"

class AGeometryObjects;

UCLASS()
class GRIDTEST_API ASimplMesh : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASimplMesh();

    UPROPERTY(VisibleDefaultsOnly)
        TArray<AGeometryObjects*> MeshComponents;

};
