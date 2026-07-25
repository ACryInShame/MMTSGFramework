// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <BaseUnit.h>
#include "UnitManager.generated.h"

//---- Event Delegates ----

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnUnitMovementFinished,
	ABaseUnit*, Unit,
	FIntPoint, EndCoords
);

UCLASS()
class MMTSGFRAMEWORK_API AUnitManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnitManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// ---- Player Turns and Rounds ----

	//process the end of a player turn resetting units
	UFUNCTION(BlueprintCallable)
	void EndTurnActions();


	//----- Units Functions -----
	UFUNCTION(BlueprintCallable)
	void DestroyUnit();

	UFUNCTION(BlueprintCallable)
	ABaseUnit* SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform UnitSpawnLocationTransform, FIntPoint GridCoords);

	//   - Unit sets and gets -
	UFUNCTION(BlueprintCallable)
	//Returns the X,Y location of the unit or -1,-1 if unit location is not found
	FIntPoint GetLocationOfUnit(ABaseUnit* TargetUnit) const;

	//Returns Unit based on X,Y location of the unit or Nullptr if unit is not found
	ABaseUnit* GetUnitByCoords(FIntPoint Coords) const;
	ABaseUnit* GetUnitByCoords(int32 X, int32 Y) const { return GetUnitByCoords( FIntPoint(X, Y) ); };

	UFUNCTION(BlueprintCallable)
	void SetUnitLocation(ABaseUnit* TargetUnit, FIntPoint NewLocation);

	UFUNCTION(BlueprintCallable)
	ABaseUnit* GetUnitByID(int32 UnitID) const;

	//Move unit to follow path, return true if unit was able to move.
	UFUNCTION(BlueprintCallable)
	bool MoveUnitDownPath(ABaseUnit* MovingUnit, const TArray<FTransform>& NewLocation, FIntPoint EndCoords);

	//----- Delegate Events -----
	UFUNCTION(Category = "Events")
	void HandleMovementFinished(ABaseUnit* Unit, FIntPoint EndCoords);

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnUnitMovementFinished OnUnitMovementFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//List of units in battle
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Units")
	TMap<ABaseUnit*, FIntPoint> Units;

	//Gets called when a unit calls their defeat function
	UFUNCTION(BlueprintCallable)
	void HandleUnitDefeated(ABaseUnit* DefeatedUnit);

private:
	UPROPERTY()
	int32 NextUnitID = 0;
};