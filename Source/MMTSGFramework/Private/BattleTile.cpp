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
