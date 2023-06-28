#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "My_ArrObject.generated.h"

USTRUCT(BlueprintType)
struct FLevelGridSlot
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FVector Location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UClass* ObjectClass;
};

UCLASS(Blueprintable)
class GRIDTEST_API AMy_ArrObject : public AActor
{
    GENERATED_BODY()

public:

    AMy_ArrObject();

    UFUNCTION(BlueprintCallable)
        void SelectGridSlot(int32 SlotIndex);

    UFUNCTION(BlueprintCallable)
        void SetSelectedObjectClass(UClass* ObjectClass);

    UFUNCTION(BlueprintCallable)
        void SpawnObjects();

protected:
    UPROPERTY(EditAnywhere, Category = "Level Designer")
        TArray<FLevelGridSlot> GridSlots;

    UPROPERTY(EditAnywhere, Category = "Level Designer")
        TSubclassOf<AActor> DefaultObjectClass;

private:
    int32 SelectedSlotIndex;
    UClass* SelectedObjectClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
        USceneComponent* SceneComponent;
};