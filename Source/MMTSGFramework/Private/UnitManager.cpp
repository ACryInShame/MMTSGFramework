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

void AUnitManager::HandleUnitDefeated(ABaseUnit* DefeatedUnit)
{
	// remove unit from unit list
	Units.Remove(DefeatedUnit);

	// destory pawn
	DefeatedUnit->Destroy();
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

ABaseUnit* AUnitManager::SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform UnitSpawnLocationTransform)
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

	Units.Add(NewUnit);

	//sunscribe to unit Defeat Event
	NewUnit->OnUnitDefeated.AddDynamic(this, &AUnitManager::HandleUnitDefeated);

	return NewUnit;
}
