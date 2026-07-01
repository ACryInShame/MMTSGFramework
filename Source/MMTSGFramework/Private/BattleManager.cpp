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
	ABaseUnit* NewUnit = UnitManager->SpawnUnit(UnitClass, UnitSpawnTransform);

	//If unit spawn fails, send log
	if (!NewUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn unit."));
		return nullptr;
	}

	return NewUnit;
}


