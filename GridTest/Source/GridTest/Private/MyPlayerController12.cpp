// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController12.h"

#include "Actor12.h"

void AMyPlayerController12::BeginPlay()
{
    Super::BeginPlay();

    // Создайте кубы и сферы и добавьте их в массивы
    for (int32 i = 0; i < 10; i++)
    {
        FVector CubeLocation = FVector(0.0f, 0.0f, i * 100.0f);
        AActor12* CubeActor = GetWorld()->SpawnActor<AActor12>(CubeLocation, FRotator::ZeroRotator);
        CubeActors.Add(CubeActor);

        FVector SphereLocation = FVector(100.0f, 0.0f, i * 100.0f);
        AActor12* SphereActor = GetWorld()->SpawnActor<AActor12>(SphereLocation, FRotator::ZeroRotator);
        SphereActors.Add(SphereActor);
    }
}