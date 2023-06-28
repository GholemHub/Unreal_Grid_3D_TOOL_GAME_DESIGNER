#include "My_ArrObject.h"
#include "Components/BoxComponent.h"

AMy_ArrObject::AMy_ArrObject()
{
    // Create the root scene component
    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    RootComponent = SceneComponent;

    // Initialize other variables
    SelectedSlotIndex = 0;
    SelectedObjectClass = nullptr;
}

void AMy_ArrObject::SelectGridSlot(int32 SlotIndex)
{
    SelectedSlotIndex = SlotIndex;
}

void AMy_ArrObject::SetSelectedObjectClass(UClass* ObjectClass)
{
    SelectedObjectClass = ObjectClass;
}

void AMy_ArrObject::SpawnObjects()
{
    if (SelectedObjectClass)
    {
        if (GridSlots.IsValidIndex(SelectedSlotIndex))
        {
            const FLevelGridSlot& SelectedSlot = GridSlots[SelectedSlotIndex];
            AActor* NewObject = GetWorld()->SpawnActor<AActor>(SelectedObjectClass, SelectedSlot.Location, FRotator::ZeroRotator);
            // You can further customize the spawned object or perform other actions
        }
    }
}
