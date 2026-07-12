// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BattleManager.h"

// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (!BattleGridBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("BattleGridBlueprint not assigned."));
	}

	BattleGrid = GetWorld()->SpawnActor<ABattleGridManager>(BattleGridBlueprint,
															GetActorTransform(),
															SpawnParams);
	if (!UnitManagerBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("UnitManagerBlueprint not assigned."));
	}

	UnitManager = GetWorld()->SpawnActor<AUnitManager>(UnitManagerBlueprint,
															GetActorTransform(),
															SpawnParams);
}

void ABattleManager::initialization()
{

}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Spawn a unit using unit manager at location on grid
ABaseUnit* ABattleManager::SpawnUnitOnGridByCoords(TSubclassOf<ABaseUnit> UnitClass, int32 GridX, int32 GridY)
{
	//Get Tile for spawn location
	ABattleTile* SpawnTile = BattleGrid->GetTileByCoords(GridX, GridY);

	if (!BattleGrid->ValidTile(SpawnTile))
		return nullptr;

	//get spawn transform from tile
	FTransform UnitSpawnTransform = SpawnTile->GetUnitAnchorTransform();

	//Spawn Unit
	ABaseUnit* NewUnit = UnitManager->SpawnUnit(UnitClass, UnitSpawnTransform, FIntPoint(GridX, GridY));

	//If unit spawn fails, send log
	if (!NewUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn unit."));
		return nullptr;
	}

	//update tile occupancy
	SpawnTile->SetOccupyingUnit(NewUnit);
	
	return NewUnit;
}

//Return a list of tiles that Unit is able to move to from current location
TArray<ABattleTile*> ABattleManager::GetMovementRange(ABaseUnit* TargetUnit)
{
	int32 MovementPoints = TargetUnit->GetMovementPoints();
	ABattleTile* StartingTile = BattleGrid->GetTileByCoords(UnitManager->GetLocationOfUnit(TargetUnit)); //Get Tile by getting Coords of unit and then getting Tile by coords of unit.
	
	//Create a list of tiles to check with the current Total movecost to get to that location from start tile
	TMap<ABattleTile*, int32> TileCheckList;
	TileCheckList.Add(StartingTile, 0); // add start tile to list with 0 since it is the start thus no cost to move to

	//Create a list of tiles that are confirmed able to move to and the cost to move to them
	TMap<ABattleTile*, int32> MoveRange;
	//MoveRange.Add(StartingTile, 0); // add start tile to list with 0 since it is the start thus no cost to move to

	while (!TileCheckList.IsEmpty()) // While list is not empty
	{
		//----Get tile with lowest MoveCostFromStart in TileCheckList
		int32 LowestCost = MAX_int32; //Set to max as highest possible cost
		ABattleTile* LowestTile = nullptr;

		//Check each tile in TileCheckList to find lowest costed tile
		for (const TPair<ABattleTile*, int32>& Pair : TileCheckList)
		{
			if (Pair.Value < LowestCost)
			{
				LowestCost = Pair.Value;
				LowestTile = Pair.Key;
			}
		}
		//----process lowest tile

		//remove tile from checklist and add to move range
		TileCheckList.Remove(LowestTile);
		MoveRange.Add(LowestTile, LowestCost);

		//get lowest tile neighbors and loop through them
		TArray<ABattleTile*> TileNeighbors = BattleGrid->GetTileNeighbors(LowestTile);

		for (ABattleTile* Tile : TileNeighbors)
		{
			//----check is unit can move to tile. ----
			//If terrain move cost is -1 then unable to move to tile, go to next tile
			if (TargetUnit->GetMovementCost(Tile->GetTerrainType()) == -1 )
				continue;

			//if tile is occupied  move to next tile
			if (Tile->GetOccupyingUnit() != nullptr)
				continue;

			//move cost to this tile is current move cost to current tile + cost to tmove to this tile
			int32 NewTileMoveCost = LowestCost + TargetUnit->GetMovementCost(Tile->GetTerrainType());

			//if move cost is greater then unit move points then unable to enter tile
			if (NewTileMoveCost > MovementPoints)
				continue;

			//if notalready in MoveRange add to MoveRange and checklist
			if (!MoveRange.Contains(Tile))
			{
				MoveRange.Add(Tile, NewTileMoveCost);
				TileCheckList.Add(Tile, NewTileMoveCost);
			}
			else //if already in list, update if current calculations are less then before and add back to TileChecklist if not already in it
			{
				if (int32* ExistingMoveCost = MoveRange.Find(Tile)) //used to only need 1 use of Find function
				{
					if (NewTileMoveCost < *ExistingMoveCost)
					{
						*ExistingMoveCost = NewTileMoveCost;
						TileCheckList.Add(Tile, NewTileMoveCost); //will update current listing is already in list
					}
				}
			}
			
		}
	}

	TArray<ABattleTile*> Output;

	for (const TPair < ABattleTile*, int32> KeyPair : MoveRange)
	{
		Output.Add(KeyPair.Key);
	}

	return Output;



	//// Reachable tiles are tile confirmed to accessible by unit
	//// Check Queue are tiles not yet confirmed but are next to be checked
	//TArray<ABattleTile*> ReachableTiles, CheckQueue;

	//FIntPoint StartCoords = GetUnitManager()->GetLocationOfUnit(TargetUnit);
	//if (!BattleGrid->ValidCoordsInGrid(StartCoords))
	//	return ReachableTiles;

	//CheckQueue.Add( (BattleGrid->GetTileByCoords(StartCoords) ) );

	//return ReachableTiles;
}

bool ABattleManager::MoveCommand(ABaseUnit* MovingUnit, ABattleTile* TargetTile)
{
	//Validate tile selection
	TArray<ABattleTile*> MoveRange = GetMovementRange(MovingUnit);

	if (!MoveRange.Contains(TargetTile))
		return false;

	//clear any tile highlights
	BattleGrid->ClearHighlightedTiles();

	/*
		Generate Path
		Store Planned Path
		Display planned path and wait for player confirm
		Execute
	*/

	//move unit and update unit location [will need to refactor so unit doesnt use tile but the transform location of tile and tiles doesnt know unit]
	//update old tile occupancy
	BattleGrid->GetTileByCoords
					( 
						GetUnitManager()->GetLocationOfUnit(MovingUnit)
					)
					->SetOccupyingUnit(nullptr);
	
	MovingUnit->MoveToTile(TargetTile);
	FIntPoint Coords(TargetTile->GetGridX(), TargetTile->GetGridY());
	UnitManager->SetUnitLocation(MovingUnit, Coords);

	//update TargetTile occupancy
	BattleGrid->GetTileByCoords(Coords)->SetOccupyingUnit(MovingUnit);

	return true;
}

void ABattleManager::HightlightMoveRange(ABaseUnit* MovingUnit)
{
	BattleGrid->ClearHighlightedTiles();

	TArray<ABattleTile*> MoveRange = GetMovementRange(MovingUnit);

	for (ABattleTile* Tile : MoveRange)
	{
		Tile->SetHighlightState(ETileHighlightState::MoveRange);
	}
}

ABattleTile* ABattleManager::GetTileOfUnit(ABaseUnit* Unit)
{
	FIntPoint Coords = UnitManager->GetLocationOfUnit(Unit);
	return BattleGrid->GetTileByCoords(Coords);
}

/*
- Get Unit MovementPoints
- Get Unit starting tile, save to MoveRange Map with 0 MoveCostFromStart
- Add Start Tile to TileCheckList Map with 0 MoveCostFromStart
- Loop while TileCheckList is not empty
	- Get tile with lowest MoveCostFromStart in TileCheckList → CurrentTile
	- Remove CurrentTile from TileCheckList
	- Get all CurrentTile Neighbors
	- Loop all Neighbors
		- Calculate NewMovementCost = CurrentTile MoveCostFromStart  (found in MoveRange Map) + MovementCost of Unit to move into currently checked Neighbor
		- If NewMovementCost > Unit Movement points
			- Continue
		- if Neighbor is not in MoveRange map
			- Add Neighbor into MoveRange with NewMovementCost
			- Add Neighbor to TileCheckList
		- else
			- if NewMovementCost < Neighbor ‘s MoveCostFromStart found in MoveRange Map
				- Update Neighbor ‘s MoveCostFromStart found in MoveRange Map = NewMovementCost
				- If Neighbor is not already in TileCheckList
				Add Neighbor to TileCheckList //This is so we can check the updated movement cost
- Create list of tiles from MoveRange Map → Return List
*/
