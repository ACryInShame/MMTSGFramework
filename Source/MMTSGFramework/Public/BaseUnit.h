// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TileTerrainType.h"
//#include "BattleTile.h"
#include "BaseUnit.generated.h"

class ABaseUnit;

//---- Event Delegates ----

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnUnitDefeated,
	ABaseUnit*,
	DefeatedUnit
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnMovementFinished,
	ABaseUnit*, MovingUnit,
	FIntPoint, EndCoords
);


UCLASS()
class MMTSGFRAMEWORK_API ABaseUnit : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseUnit();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//------------Gets/Sets----------------
	UFUNCTION(BlueprintCallable)
	const int32 GetMovementPoints() { return MovementPoints; }
	UFUNCTION(BlueprintCallable)
	const FString GetUnitName() { return UnitName; }
	UFUNCTION(BlueprintCallable)
	const int32 GetCurrentHealth() { return CurrentHealth; }
	UFUNCTION(BlueprintCallable)
	const int32 GetMaxHealth() { return MaxHealth; }
	UFUNCTION(BlueprintCallable)
	const int32 GetUnitID() { return UnitID; }

	//----
	UFUNCTION(BlueprintCallable)
	void SetUnitID(int32 newID) { UnitID = newID; }


	//------------Combat----------------
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(int32 Amount);

	UFUNCTION(BlueprintCallable)
	int32 DealDamage();

	UFUNCTION(BlueprintCallable)
	void DefeatUnit();


	//------------Events----------------
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnUnitDefeated OnUnitDefeated;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMovementFinished OnMovementFinished;

	// ------------Movement----------------
	//Start movement for unit, initalizes variables for movement
	UFUNCTION(BlueprintCallable)
	void BeginMovement(const TArray<FTransform>& Path, FIntPoint EndCoords);

	//return the cost to move into a particular terrian type
	UFUNCTION(BlueprintCallable)
	int32 GetMovementCost(ETileTerrainType InTerrainType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Data")
	int32 UnitID = INDEX_NONE;

	//Unit ------------Attributes----------------
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	FString UnitName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 AttackPower; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 DefencePoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 MovementPoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	TMap<ETileTerrainType, int32> MovementCosts;


	//Unit ------------Movement----------------
	TArray<FTransform> CurrentPath;
	int32 CurrentPathIndex;
	FIntPoint MovementEndCoords;
	bool bMoving; //is a boolean to tell if unit is currently moving or not, not currently in use but may become useful later.
	FTransform CurrentDestination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MoveSpeed = 300.0f;

	void UpdateMovement(float DeltaTime);
	void MovementComplete();
};
