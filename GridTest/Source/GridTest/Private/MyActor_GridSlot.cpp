#include "MyActor_GridSlot.h"

AMyActor_GridSlot::AMyActor_GridSlot()
{
    for (AActor* Match : Matches)
    {
        FString ObjectName = Match->GetName();
        UE_LOG(LogTemp, Warning, TEXT("Object Name: %s"), *ObjectName);
    }
}
