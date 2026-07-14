// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "UnitManager.h"

// Sets default values
AUnitManager::AUnitManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnitManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnitManager::DestroyUnit()
{
}

ABaseUnit* AUnitManager::SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform UnitSpawnLocationTransform, FIntPoint GridCoords)
{
	//Set spawn Params to always spawn unit. This allows units to spawn even if they slightly overlap terrain
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//Spawn Unit
	ABaseUnit* NewUnit = GetWorld()->SpawnActor<ABaseUnit>(UnitClass, UnitSpawnLocationTransform, SpawnParams);


	//If unit spawn fails, send log and return null pointer
	if (!NewUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn unit."));
		return nullptr;
	}

	Units.Add(NewUnit, GridCoords);

	//subscribe to unit Defeat Event
	NewUnit->OnUnitDefeated.AddDynamic(this, &AUnitManager::HandleUnitDefeated);

	return NewUnit;
}

bool AUnitManager::MoveUnitDownPath(ABaseUnit* MovingUnit, const TArray<FTransform>& MovementPath, FIntPoint EndCoords)
{
	//check if input is valid
	if (!Units.Find(MovingUnit))
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Unit in UnitManager::MoveUnitDownPath"));
		return false;
	}
	if (MovementPath.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid MovePath in UnitManager::MoveUnitDownPath"));
		return false;
	}
	if (EndCoords.X < 0 || EndCoords.Y < 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalud EndCoords in UnitManager::MoveUnitDownPath"));
		return false;
	}

	//subscribe to unit movement to know when unit finishes move
	MovingUnit->OnMovementFinished.AddDynamic(
		this,
		&AUnitManager::HandleMovementFinished
	);

	//Have Unit Move
	MovingUnit->BeginMovement(MovementPath,EndCoords);

	return true;
}

void AUnitManager::HandleMovementFinished(ABaseUnit* Unit, FIntPoint EndCoords)
{
	// Update Unit coords in TMap
	*Units.Find(Unit) = EndCoords;
	
	//remove binding
	Unit->OnMovementFinished.RemoveDynamic(
		this,
		&AUnitManager::HandleMovementFinished
	);

	// Notify BattleManager via event
	OnUnitMovementFinished.Broadcast(Unit, EndCoords);
}

void AUnitManager::HandleUnitDefeated(ABaseUnit* DefeatedUnit)
{
	// remove unit from unit list
	Units.Remove(DefeatedUnit);

	// destory pawn
	DefeatedUnit->Destroy();
}