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

// Called to bind functionality to input
void AUnitManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//ABaseUnit* AUnitManager::SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform SpawnTransform)
//{
//	ABaseUnit* NewUnit = GetWorld()->SpawnActor<ABaseUnit>(UnitClass, SpawnTransform);
//
//	if (NewUnit)
//		Units.Add(NewUnit);
//	NewUnit->Initalize();
//
//	return NewUnit;
//}

void AUnitManager::DestroyUnit()
{
}

void AUnitManager::GetUnitByID()
{
}

ABaseUnit* AUnitManager::SpawnUnitOnGridByCoords(TSubclassOf<ABaseUnit> UnitClass, int32 GridX, int32 GridY)
{
	if (!BattleGrid)
	{
		return nullptr;
	}

	FTransform UnitSpawnTransform = BattleGrid->GetTileSpawnLocation(GridX, GridY);


	ABaseUnit* NewUnit = GetWorld()->SpawnActor<ABaseUnit>(UnitClass, UnitSpawnTransform);

	if (NewUnit)
		Units.Add(NewUnit);
	NewUnit->Initalize(BattleGrid->GetTileByCoords(GridX,GridY));

	return NewUnit;
}
