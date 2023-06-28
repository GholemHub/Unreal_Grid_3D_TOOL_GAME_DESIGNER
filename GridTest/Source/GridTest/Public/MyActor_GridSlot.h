#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor_GridSlot.generated.h"

UCLASS()
class GRIDTEST_API AMyActor_GridSlot : public AActor
{
	GENERATED_BODY()

public:
	AMyActor_GridSlot();

	UPROPERTY(EditAnywhere, Category = "MainObject")
		TArray<class AActor*> Matches;
};
