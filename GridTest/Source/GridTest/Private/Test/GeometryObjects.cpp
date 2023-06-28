#include "Test/GeometryObjects.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"

AGeometryObjects::AGeometryObjects()
{
    UStaticMesh* Mesh = nullptr;

    switch (SelectedGeometry)
    {
    case EGeometrySelection1::Sphere:
    {
        static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
        if (MeshAsset.Succeeded())
        {
            Mesh = MeshAsset.Object;
        }
        break;
    }
    case EGeometrySelection1::Cylinder:
    {
        static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
        if (MeshAsset.Succeeded())
        {
            Mesh = MeshAsset.Object;
        }
        break;
    }
    default:
        break;
    }

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    MeshComponent->SetStaticMesh(Mesh);

    MeshComponent->RegisterComponent();

    // Mark the render state as dirty to update the viewport
    //MeshComponent->MarkRenderStateDirty();
}

void AGeometryObjects::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGeometryObjects, SelectedGeometry))
    {
        // SelectedGeometry property has been modified
        
        // Update the constructor based on the new SelectedGeometry value
        UpdateConstructor();
    }

    Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AGeometryObjects::UpdateConstructor()
{
    //MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    // Clear the previous MeshComponent if any
    if (MeshComponent != nullptr)
    {
        MeshComponent->UnregisterComponent();
        MeshComponent = nullptr;
    }

    // Update the MeshComponent based on the SelectedGeometry
    switch (SelectedGeometry)
    {
    case EGeometrySelection1::Sphere:
    {
        // Load the sphere static mesh
        static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
        if (SphereMeshAsset.Succeeded())
        {
            UStaticMesh* SphereMesh = SphereMeshAsset.Object;

            // Create and set the static mesh component
            MeshComponent = NewObject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
            MeshComponent->SetStaticMesh(SphereMesh);

            // Register the mesh component to update the viewport
            MeshComponent->RegisterComponent();
            MeshComponent->MarkRenderStateDirty();
        }
    }
    break;
    case EGeometrySelection1::Cube:
    {
        // Load the cube static mesh
        static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
        if (CubeMeshAsset.Succeeded())
        {
            UStaticMesh* CubeMesh = CubeMeshAsset.Object;

            // Create and set the static mesh component
            MeshComponent = NewObject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
            MeshComponent->SetStaticMesh(CubeMesh);

            // Register the mesh component to update the viewport
            MeshComponent->RegisterComponent();
            MeshComponent->MarkRenderStateDirty();
        }
    }
    break;
    case EGeometrySelection1::Cylinder:
    {
        // Load the cylinder static mesh
        static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
        if (CylinderMeshAsset.Succeeded())
        {
            UStaticMesh* CylinderMesh = CylinderMeshAsset.Object;

            // Create and set the static mesh component
            MeshComponent = NewObject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
            MeshComponent->SetStaticMesh(CylinderMesh);

            // Register the mesh component to update the viewport
            MeshComponent->RegisterComponent();
            MeshComponent->MarkRenderStateDirty();
        }
    }
    break;
    default:
        // Invalid selection or no selection
        break;
    }
}
