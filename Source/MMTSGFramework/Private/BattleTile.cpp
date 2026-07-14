// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BattleTile.h"

// Sets default values
ABattleTile::ABattleTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));

    //update mesh and then set root to updated mesh
	RootComponent = TileMesh;
}

// Called when the game starts or when spawned
void ABattleTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//override of UE constructor
void ABattleTile::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    UpdateStaticMesh();
    DynamicMaterial = TileMesh->CreateAndSetMaterialInstanceDynamic(0);
    UpdateMaterial();
}

void ABattleTile::UpdateMaterial()
{
    if (!DynamicMaterial)
    {
        return;
    }

    //update Material Color
    DynamicMaterial->SetVectorParameterValue(
        TEXT("TerrainColor"),
        GetTerrainColor()
    );

    switch (HighLightState)
    {
    case ETileHighlightState::None:
        DynamicMaterial->SetScalarParameterValue("HighlightStrength", 0.f);
        break;

    case ETileHighlightState::Selected:
        DynamicMaterial->SetVectorParameterValue("HighlightColor", FLinearColor::Yellow);
        DynamicMaterial->SetScalarParameterValue("HighlightStrength", 0.5f);
        break;

    case ETileHighlightState::MoveRange:
        DynamicMaterial->SetVectorParameterValue("HighlightColor", FLinearColor::Blue);
        DynamicMaterial->SetScalarParameterValue("HighlightStrength", 0.5f);
        break;
    }
}

void ABattleTile::ClearHighlight()
{
    HighLightState = ETileHighlightState::None;
    UpdateMaterial();
}

//updated the tile mesh based on the type of tile being spawned
void ABattleTile::UpdateStaticMesh()
{
    switch (TileShape)
    {
    case TileShapeType::Square:
        TileMesh->SetStaticMesh(SquareMesh);
        break;

    case TileShapeType::HexFlatTop:
        TileMesh->SetStaticMesh(FlatHexMesh);
        break;

    case TileShapeType::HexPointedTop:
        TileMesh->SetStaticMesh(PointedHexMesh);
        break;
    }
}

FTransform ABattleTile::GetUnitAnchorTransform() const
{
    if (!TileMesh)
    {
        return FTransform::Identity;
    }

    FVector Min;
    FVector Max;

    TileMesh->GetLocalBounds(Min, Max);

    FVector AnchorLocation = GetActorLocation();

    // Move to top of mesh
    AnchorLocation.Z += Max.Z;

    return FTransform(AnchorLocation);
}

FString ABattleTile::GetTerrainName() const
{
    return UEnum::GetValueAsString(TerrainType);
}

FLinearColor ABattleTile::GetTerrainColor() const
{
    switch (TerrainType)
    {
    case ETileTerrainType::Grass:
        return FLinearColor::Green;

    case ETileTerrainType::Dirt:
        return FLinearColor(0.5f, 0.25f, 0.0f);

    case ETileTerrainType::Sand:
        return FLinearColor::Yellow;

    case ETileTerrainType::Water:
        return FLinearColor::Blue;

    case ETileTerrainType::Forest:
        return FLinearColor(0.0f, 0.4f, 0.0f);

    case ETileTerrainType::Mountain:
        return FLinearColor::Gray;
    }

    return FLinearColor::White;
}