// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BattleGridManager.h"

// Sets default values
ABattleGridManager::ABattleGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABattleGridManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleGridManager::GenerateGrid()
{
	//Set starting spawn point
	FVector GridStartingSpawn = FVector::ZeroVector;

	//Destory any current Grid
	for (ABattleTile* Tile : BattleGrid)
	{
		if (IsValid(Tile))
		{
			Tile->Destroy();
		}
	}

	//Empty the TArray of any pointers left over
	BattleGrid.Empty();

	//Check if Tile BP is assigned properly
	if (!TileBPClass)
	{
		UE_LOG(LogTemp, Error, TEXT("TileBPClass is null."));
		UE_LOG(LogTemp, Warning, TEXT("TileBPClass is null."));
		return;
	}

	//Variables to hold Constants used in grid Generator
	float TileMeshX = 0.0f , TileMeshY = 0.0f;
	bool TileSizeInitialized = false;

	//reserve array size for aptimization
	BattleGrid.Reserve(SizeX * SizeY);

	//X count
	for (int32  x=0;x < SizeX;x++)
	{
		//Y count
		for (int32  y = 0;y < SizeY; y++)
		{
			

			//Delay spawn Tile in order to set variables before Tile constructor
			ABattleTile* CurrentTile = GetWorld()->SpawnActorDeferred<ABattleTile>(
				TileBPClass,
				FTransform::Identity, //Spawn at 0.0.0
				nullptr, // Owner
				nullptr, // Instigator
				ESpawnActorCollisionHandlingMethod::AlwaysSpawn //will ensure a tile is always created
			);

			//Check if tile spawned correctly
			if (!CurrentTile)
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to spawn tile."));
				UE_LOG(LogTemp, Warning, TEXT("Failed to spawn tile."));
				continue;
			}
				
			//set Tile variables before spawning
			CurrentTile->SetTileShapeType(GridTileType);
			CurrentTile->SetGridX(x);
			CurrentTile->SetGridY(y);

			int32 NumTerrain = static_cast<int32>(ETileTerrainType::MAX) -1;  //grabs last enum which is the highest number but -1 as MAX itself is not a possible option
			int32 RandomTerrain = FMath::RandRange(0, NumTerrain );

			CurrentTile->SetTerrainType(
				static_cast<ETileTerrainType>(RandomTerrain)
			);

			//Spawn Tile at 0.0.0 to be moved later
			CurrentTile->FinishSpawning(FTransform::Identity);

			if (!TileSizeInitialized) //If first tile, use Tile to set constants
			{
				FVector Min;
				FVector Max;

				CurrentTile->GetTileMesh()->GetLocalBounds(Min, Max);

				TileMeshX = Max.X - Min.X; //Take max and Min to get size of model
				TileMeshY = Max.Y - Min.Y; //Take max and Min to get size of model

				TileSizeInitialized = true;
			}

			//Calculate Spawn Location
			FVector SpawnLocation = GridStartingSpawn;

			//Caclulations from https://www.redblobgames.com/grids/hexagons/ 
			switch (GridTileType)
			{
			case TileShapeType::Square:
				SpawnLocation.X = GridStartingSpawn.X + (x * TileMeshX);
				SpawnLocation.Y = GridStartingSpawn.Y + (y * TileMeshY);
				break;

			case TileShapeType::HexFlatTop:
				SpawnLocation.X = x * ( TileMeshX * 0.75) ;

				SpawnLocation.Y = y * TileMeshY;

				if (x % 2 == 1)
				{
					SpawnLocation.Y += TileMeshY * 0.5f;
				}
				break;

			case TileShapeType::HexPointedTop:
				SpawnLocation.X = x * TileMeshX;

				SpawnLocation.Y = y * (TileMeshY * 0.75 );

				if (y % 2 == 1)
				{
					SpawnLocation.X += TileMeshX * 0.5f;
				}
				break;
			}

			//Move to calculated location
			CurrentTile->SetActorLocation(SpawnLocation);

			//Add new Tile to Array
			BattleGrid.Add(CurrentTile);
		}
	}
}

ABattleTile* ABattleGridManager::GetTileByCoords(int32 X, int32 Y)
{
	// check if valid grid location and if location is in battlegrid
	if (!ValidCoordsInGrid(X, Y))
		return nullptr;

	int32 Index = (X * SizeY) + Y;
	if (!BattleGrid.IsValidIndex(Index))
		return nullptr;

	//if so, return tile
	return BattleGrid[Index];
}

bool ABattleGridManager::ValidCoordsInGrid(int32 X, int32 Y)
{
	if (X <= 0 || Y <= 0)
		return false;
	if (X > SizeX || Y > SizeY)
		return false;

	return true;
}

