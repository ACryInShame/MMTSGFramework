// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputAction.h"
#include <BattleGridManager.h>
#include <UnitManager.h>
#include <TacticalCommands.h>
#include "ETileHighlightState.h"
#include "BattleManager.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//---- Gets and Sets ----
	UFUNCTION(BlueprintCallable)
	ABattleGridManager* GetBattleGrid() { return BattleGrid; }

	UFUNCTION(BlueprintCallable)
	AUnitManager* GetUnitManager() { return UnitManager; }


	//---- Unit functions and commands ----

	//process commands given by PlayerController or AI
	bool ExecuteCommand(const FTacticalCommand& Command);

	//process commands given by PlayerController or AI
	bool ExecuteMove(const FTacticalCommand& Command);

	//Spawn a unit using unit manager at location on grid
	UFUNCTION(BlueprintCallable)
	ABaseUnit* SpawnUnitOnGridByCoords(TSubclassOf<ABaseUnit> UnitClass, int32 CoordsX, int32 CoordsY);

	//Command a unit to move to a tile, returns true or flase if unit was able to move to location
	UFUNCTION(BlueprintCallable)
	bool MoveCommand(ABaseUnit* MovingUnit, ABattleTile* TargetTile);

	// ---- Grid and Tile Functions ---
	//Returns list of tiles based on the movement range of unit, takes terrain into account
	UFUNCTION(BlueprintCallable)
	TArray<ABattleTile*> GetMovementRange(ABaseUnit* TargetUnit);

	//highlights tiles based on the movement range of unit, takes terrain into account
	UFUNCTION(BlueprintCallable)
	void HightlightMoveRange(ABaseUnit* MovingUnit);

	//returns the tile the unit occupies
	UFUNCTION(BlueprintCallable)
	ABattleTile* GetTileOfUnit(ABaseUnit* Unit);

	//returns the Unit by their location
	UFUNCTION(BlueprintCallable)
	ABaseUnit* GetUnitByCoords(FIntPoint Coords);

	//Find path between unit and tile using modified A* taking terrain into account
	UFUNCTION(BlueprintCallable)
	TArray<ABattleTile*> GetMovementPath(ABaseUnit* MovingUnit, ABattleTile* EndTile);

	// ---- Delegate Events ----
	UFUNCTION(Category = "Events")
	void HandleMovementFinished(ABaseUnit* Unit, FIntPoint EndCoords);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void initialization();

	// ---- Manager Variables ----
	UPROPERTY() //To prevent Unreal Engine Garbage colltion from accidently removing it
	ABattleGridManager* BattleGrid = nullptr;
	UPROPERTY() //To prevent Unreal Engine Garbage colltion from accidently removing it
	AUnitManager* UnitManager = nullptr;

	UPROPERTY(EditAnywhere, Category = "Managers")
	TSubclassOf<ABattleGridManager> BattleGridBlueprint;

	UPROPERTY(EditAnywhere, Category = "Managers")
	TSubclassOf<AUnitManager> UnitManagerBlueprint;
};