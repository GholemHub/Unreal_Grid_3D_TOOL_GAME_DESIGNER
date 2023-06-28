#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorPair.generated.h"

UCLASS()
class GRIDTEST_API AActorPair : public AActor
{
    GENERATED_BODY()

public:
    AActorPair();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
        class USceneComponent* RootSceneComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
        class UStaticMeshComponent* Actor1MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
        class UStaticMeshComponent* Actor2MeshComponent;

    UFUNCTION(BlueprintCallable, Category = "Actor Pair")
        void SetActorLocation(int32 ActorIndex, FVector NewLocation);

private:
    FVector Actor1Location;
    FVector Actor2Location;
};