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

	// spawn Battle Grid and Unit Manager
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (!BattleGridBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("BattleGridBlueprint not assigned."));
		return;
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

	// subscribe to unit finsihed event
	UnitManager->OnUnitMovementFinished.AddDynamic(
		this,
		&ABattleManager::HandleMovementFinished);
}

void ABattleManager::Initialize()
{

}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleManager::EndTurnActions()
{
	//reset all units to be able to act again
	UnitManager->EndTurnActions();
}

bool ABattleManager::ExecuteCommand(const FTacticalCommand& Command)
{
	switch (Command.Type)
	{
	case ETacticalCommandType::Move:
		return ExecuteMove(Command);
		break;

	case ETacticalCommandType::Attack:
		return ExecuteAttack(Command);
		break;

	case ETacticalCommandType::Wait:
		//return ExecuteWait(Command);
		break;

	default:
		return false;
	}

	return false;
}

bool ABattleManager::ExecuteMove(const FTacticalCommand& Command)
{
	ABaseUnit* SourceUnit =
		UnitManager->GetUnitByID(Command.SourceUnitID);

	if (!SourceUnit)
	{

		UE_LOG(LogTemp, Error, TEXT("No unit in ABattleManager::ExecuteMove"));

		return false;
	}

	ABattleTile* DestinationTile = BattleGrid->GetTileByCoords(Command.TargetCoords);

	if (!BattleGrid->ValidTile(DestinationTile))
	{
		UE_LOG(LogTemp, Error, TEXT("Not a valid Tile in ABattleManager::ExecuteMove"));

		return false;
	}
	return MoveCommand(SourceUnit, DestinationTile );
}

bool ABattleManager::ExecuteAttack(const FTacticalCommand& Command)
{
	ABaseUnit* SourceUnit =
		UnitManager->GetUnitByID(Command.SourceUnitID);

	if (!SourceUnit)
	{

		UE_LOG(LogTemp, Error, TEXT("No unit in ABattleManager::ExecuteAttack"));

		return false;
	}

	ABattleTile* DestinationTile = BattleGrid->GetTileByCoords(Command.TargetCoords);

	if (!BattleGrid->ValidTile(DestinationTile))
	{
		UE_LOG(LogTemp, Error, TEXT("Not a valid Tile in ABattleManager::ExecuteAttack"));

		return false;
	}
	return AttackCommand(SourceUnit, DestinationTile);
}

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

			// ---- ----

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

	//create list of tiles from TPair
	TArray<ABattleTile*> Output;

	for (const TPair < ABattleTile*, int32> KeyPair : MoveRange)
	{
		Output.Add(KeyPair.Key);
	}

	return Output;
}

TArray<ABattleTile*> ABattleManager::GetAttackRange(ABaseUnit* TargetUnit)
{
	// ---- Temp for MVP, used movement range calculations but doesnt ignore units ----
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
			if (TargetUnit->GetMovementCost(Tile->GetTerrainType()) == -1)
				continue;

			//Removed from Movement calculations as attack is okay with units
			////if tile is occupied  move to next tile
			//if (Tile->GetOccupyingUnit() != nullptr)
			//	continue;

			//move cost to this tile is current move cost to current tile + cost to tmove to this tile
			int32 NewTileMoveCost = LowestCost + TargetUnit->GetMovementCost(Tile->GetTerrainType());

			//if move cost is greater then unit move points then unable to enter tile
			if (NewTileMoveCost > MovementPoints)
				continue;

			// ---- ----

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


	//create list of tiles from TPair
	TArray<ABattleTile*> Output;

	for (const TPair < ABattleTile*, int32> KeyPair : MoveRange)
	{
		Output.Add(KeyPair.Key);
	}

	return Output;
}

bool ABattleManager::MoveCommand(ABaseUnit* MovingUnit, ABattleTile* TargetTile)
{
	//Clear tile highlights
	BattleGrid->ClearHighlightedTiles();

	//Validate tile input
	if (!MovingUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Unit in BattleManager::MoveCommand"));
		return false;
	}
	if (!TargetTile)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Tile in BattleManager::MoveCommand"));
		return false;
	}

	//Is player Turn?

	//get unit movement range
	TArray<ABattleTile*> MoveRange = GetMovementRange(MovingUnit);

	//Is Target Reachable?
	if (!MoveRange.Contains(TargetTile))
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to get movement range from unit in BattleManager::MoveCommand"));
		return false;
	}

	//is tile occupied
	if (TargetTile->GetOccupyingUnit() != nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Selected Tile is occupied, unable to move to tile in BattleManager::MoveCommand"));
		return false;
	}

	//---- Generate Movement Path -----

	//get path of tiles, then change over to path of transforms for unit movement
	TArray<ABattleTile*> MovementPathTiles = GetMovementPath(MovingUnit, TargetTile);
	TArray<FTransform> MovementPath;

	for (ABattleTile* Tile : MovementPathTiles)
	{
		MovementPath.Add(Tile->GetUnitAnchorTransform());
	}

	//change tile path over to path of transforms for unit to follow

	/*
	* ---- This are planned for future iterrations but are deferred for MVP ----
		Store Planned Path
		Display planned path and wait for player confirm
	*/

	//move unit and update unit location [will need to refactor so unit doesnt use tile but the transform location of tile and tiles doesnt know unit]
	
	//update old tile occupancy
	BattleGrid->GetTileByCoords
					( 
						GetUnitManager()->GetLocationOfUnit(MovingUnit)
					)
					->SetOccupyingUnit(nullptr);
	
	//Move unit along path
	//MovingUnit->MoveToTile(TargetTile);
	//MovingUnit->BeginMovement(MovementPath);
	FIntPoint Coords(TargetTile->GetGridX(), TargetTile->GetGridY());
	UnitManager->MoveUnitDownPath(MovingUnit, MovementPath, Coords);

	return true;
}

bool ABattleManager::AttackCommand(ABaseUnit* AttackingUnit, ABattleTile* TargetTile)
{
	//Clear tile highlights
	BattleGrid->ClearHighlightedTiles();

	//Validate tile input
	if (!AttackingUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Unit in BattleManager::AttackCommand"));
		return false;
	}
	if (!TargetTile)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Tile in BattleManager::AttackCommand"));
		return false;
	}

	//Is player Turn?

	//get unit movement range
	TArray<ABattleTile*> AttackRange = GetAttackRange(AttackingUnit);

	//Is Target Reachable?
	if (!AttackRange.Contains(TargetTile))
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to get attack range from unit in BattleManager::AttackCommand"));
		return false;
	}

	//Attack Target Unit
	//Animations and such will set to play at this time like the movement does
	//Attack to tile also happens here for AOE attacks, not set in MVP


	//Get unit on tile
	ABaseUnit* TargetUnit = GetUnitByCoords(FIntPoint(TargetTile->GetGridX(), TargetTile->GetGridY()));

	if (TargetUnit)
	{
		int32 Damage = AttackingUnit->DealDamage();
		TargetUnit->ApplyDamage(Damage);

		#if !UE_BUILD_SHIPPING
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.0f,
				FColor::Yellow,
				FString::Printf(TEXT("Attacked for %d Damage"), Damage)
			);
		}
		#endif	
	}

	//Attack Tile
	// 
	//Nothing for MVP
	#if !UE_BUILD_SHIPPING
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Yellow,
			FString::Printf(TEXT("Empty Tile hit") )
		);
	}
	#endif

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

void ABattleManager::HightlightAttackRange(ABaseUnit* AttackinhgUnit)
{
	BattleGrid->ClearHighlightedTiles();

	TArray<ABattleTile*> AttackRange = GetAttackRange(AttackinhgUnit);

	for (ABattleTile* Tile : AttackRange)
	{
		Tile->SetHighlightState(ETileHighlightState::AttackRange);
	}
}

ABattleTile* ABattleManager::GetTileOfUnit(ABaseUnit* Unit)
{
	FIntPoint Coords = UnitManager->GetLocationOfUnit(Unit);
	return BattleGrid->GetTileByCoords(Coords);
}

ABaseUnit* ABattleManager::GetUnitByCoords(FIntPoint Coords)
{
	return 	UnitManager->GetUnitByCoords(Coords);
}

// Node for pathfinding
struct PathNode
{
	FIntPoint Coords;
	ABattleTile* Tile;

	int32 MoveCostFromStart; //GCost
	int32 DistanceToEnd; //HCost

	PathNode* ParentNode;

	int32 FCost() const //FCost
	{
		return MoveCostFromStart + DistanceToEnd;
	}


	//Compare checks for coord and tile checks
	bool operator==(const PathNode& Other) const
	{
		return Coords == Other.Coords;
	}

	bool operator==(const ABattleTile* OtherTile) const
	{
		return Tile == OtherTile;
	}

};

TArray<ABattleTile*> ABattleManager::GetMovementPath(ABaseUnit* MovingUnit, ABattleTile* EndTile)
{
	//Get Starting Tile
	ABattleTile* StartingTile = BattleGrid->GetTileByCoords(UnitManager->GetLocationOfUnit(MovingUnit)); //Get Tile by getting Coords of unit and then getting Tile by coords of unit.

	// create a starting path node
	PathNode* StartingNode = new PathNode();
	StartingNode->Coords = FIntPoint(StartingTile->GetGridX(), StartingTile->GetGridY());
	StartingNode->MoveCostFromStart = 0;
	StartingNode->DistanceToEnd = BattleGrid->GetDistanceBetweenTiles(StartingTile, EndTile);
	StartingNode->Tile = StartingTile;
	StartingNode->ParentNode = nullptr;

	TArray< PathNode* >  OpenList, ClosedList; //Open list are tiles still avilable to use while Close list are tiles checked and cannot be used.

	OpenList.Add(StartingNode);

	while (!OpenList.IsEmpty()) // while there are tiles to check contunie searching
	{
		//Find Tile with lowest movement cost
		int32 LowestCost = MAX_int32; //Set to max as highest possible cost
		PathNode* LowestCostNode = nullptr;

		for (PathNode* Node : OpenList)
		{
			if (Node->FCost() < LowestCost)
			{
				LowestCost = Node->FCost();
				LowestCostNode = Node;
			}
		}

		if (!LowestCostNode)
			break;

		//if current lowest is the EndTile, construct path and return
		if (LowestCostNode->Tile == EndTile)
		{
			TArray<ABattleTile*> Output;
			//Reconstruct path
			PathNode* CurrentNode = LowestCostNode;
			
			while (CurrentNode != nullptr)
			{
				Output.Add(CurrentNode->Tile);

				if (CurrentNode->Tile == StartingTile)
					break;

				CurrentNode = CurrentNode->ParentNode;
			}

			//memory clenup
			for (PathNode* Node : OpenList)
				delete Node;

			for (PathNode* Node : ClosedList)
				delete Node;
			
			//Reverse Output
			Algo::Reverse(Output);

			//return path
			return Output;
		}

		//Move Lowest to closed list as it's being checked now
		ClosedList.Add(LowestCostNode);
		OpenList.Remove(LowestCostNode);

		//Check each neighbor and add tiles able to move into, into the open list
		TArray<ABattleTile*> NodeNeighbors = BattleGrid->GetTileNeighbors(LowestCostNode->Tile);

		for (ABattleTile* Tile : NodeNeighbors)
		{
			//----check is unit can move to tile. ----
			//If terrain move cost is -1 then unable to move to tile, go to next tile
			if (MovingUnit->GetMovementCost(Tile->GetTerrainType()) == -1)
				continue;

			//if tile is occupied  move to next tile
			if (Tile->GetOccupyingUnit() != nullptr)
				continue;

			//if tile is already in closed list continue
			if (ClosedList.ContainsByPredicate
					(
						[Tile](const PathNode* Node)
						{
							return Node->Tile == Tile;
						}
					)
				)
			{
				continue;
			}

			//get move cost to this tile : equal to current move cost to lowestcost node tile + cost to to move to this tile
			int32 NewTileMoveCost = LowestCostNode->MoveCostFromStart + MovingUnit->GetMovementCost(Tile->GetTerrainType());

			//if move cost is greater then unit move points then unable to enter tile
			if (NewTileMoveCost > MovingUnit->GetMovementPoints())
				continue;
			//---- ----

			//if not already in OpenList add to OpenList
			if (!OpenList.ContainsByPredicate
				(
					[Tile](const PathNode* Node)
					{
						return Node->Tile == Tile;
					})
				)
			{
				PathNode* TempPathNode = new PathNode();
				TempPathNode->Coords = FIntPoint(Tile->GetGridX(), Tile->GetGridY());
				TempPathNode->MoveCostFromStart = NewTileMoveCost;
				TempPathNode->DistanceToEnd = BattleGrid->GetDistanceBetweenTiles(Tile, EndTile);
				TempPathNode->Tile = Tile;
				TempPathNode->ParentNode = LowestCostNode;

				OpenList.Add(TempPathNode);
			}
			else //if already in list, update if current calculations are less then before
			{
				if (PathNode** ExistingNode =
						OpenList.FindByPredicate
						(
							[Tile](const PathNode* Node)
							{
								return Node->Tile == Tile;
							}
						)
					)
				{
					if (NewTileMoveCost < (*ExistingNode)->MoveCostFromStart)
					{
						(*ExistingNode)->MoveCostFromStart = NewTileMoveCost;
						(*ExistingNode)->ParentNode = LowestCostNode;

						//not needed as distance should not change but left here as a note for future reference
						//(*ExistingNode)->DistanceToEnd = BattleGrid->GetDistanceBetweenTiles((*ExistingNode)->Tile, EndTile);
					}
				}
			}
		}
	}

	//---- return empty array if unable to find path ----

	//memory clenup
	for (PathNode* Node : OpenList)
		delete Node;

	for (PathNode* Node : ClosedList)
		delete Node;
	return TArray<ABattleTile*>();
}

void ABattleManager::HandleMovementFinished(ABaseUnit* MovingUnit,FIntPoint Coords)
{
	//After move finishes
	//update TargetTile occupancy
	BattleGrid->GetTileByCoords(Coords)->SetOccupyingUnit(MovingUnit);
}