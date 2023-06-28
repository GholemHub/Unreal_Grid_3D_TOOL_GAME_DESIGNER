#include "Test/SimplMesh.h"
#include "Test/GeometryObjects.h"
#include "Engine/StaticMesh.h"

ASimplMesh::ASimplMesh()
{
    PrimaryActorTick.bCanEverTick = false;

    // Check if this is the first instance of ASimplMesh being constructed
    static bool bFirstInstance = true;

    if (!bFirstInstance == true) {
        bFirstInstance = !bFirstInstance;
        return;
    }
    
    FVector SpawnLocation(0.f, 0.f, 0.f); // Starting spawn location

    // Load the sphere static mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    UStaticMesh* SphereMesh = nullptr;
    if (SphereMeshAsset.Succeeded())
    {
        SphereMesh = SphereMeshAsset.Object;
    }
    UWorld* World = GetWorld();
    UE_LOG(LogTemp, Warning, TEXT("3--"));
    if (SphereMesh)
    {
        for (int32 XIndex = 0; XIndex < 2; XIndex++)
        {
            for (int32 YIndex = 0; YIndex < 2; YIndex++)
            {
                for (int32 ZIndex = 0; ZIndex < 2; ZIndex++)
                {
                    UE_LOG(LogTemp, Warning, TEXT("1"));
                    if (World)
                    {
                        AGeometryObjects* NewBoxActor = World->SpawnActor<AGeometryObjects>(AGeometryObjects::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
                        MeshComponents.Add(NewBoxActor);
                        UE_LOG(LogTemp, Warning, TEXT("2"));
                    }
                    SpawnLocation.Z += 200.f;
                }
                SpawnLocation.Y += 200.f;
                SpawnLocation.Z = 0.f;
            }
            SpawnLocation.X += 200.f;
            SpawnLocation.Y = 0.f;
        }
    }
}
