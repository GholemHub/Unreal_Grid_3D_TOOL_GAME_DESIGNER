#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EditableArray.generated.h"

USTRUCT()
struct FInnerArray
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, Category = "My Array")
        TArray<AActor*> ArrayOfInts;
};

USTRUCT()
struct FInnerArray2
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, Category = "My Array")
        TArray<FInnerArray> ArrayOfInts;
};

UCLASS()
class GRIDTEST_API AEditableArray : public AActor
{
    GENERATED_BODY()

public:
    AEditableArray();

    UPROPERTY(EditAnywhere, Category = "My Array")
        TArray<FInnerArray2> My3DArray;

    UPROPERTY(EditAnywhere, Category = "My Array")
        TSubclassOf<AActor> Element;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor Pair")
        USceneComponent* RootSceneComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor Pair")
        UStaticMeshComponent* Actor1MeshComponent;
};