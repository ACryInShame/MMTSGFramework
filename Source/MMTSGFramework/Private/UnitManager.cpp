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

void AUnitManager::SpawnUnit()
{
}

void AUnitManager::DestroyUnit()
{
}

void AUnitManager::GetUnitByID()
{
}

void AUnitManager::SpawnUnitOnGridBuCoords(ABaseUnit* NewUnit, int32 X, int32 Y)
{
	
}
