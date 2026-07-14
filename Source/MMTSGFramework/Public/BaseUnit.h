// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TileTerrainType.h"
//#include "BattleTile.h"
#include "BaseUnit.generated.h"

class ABaseUnit;

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
	////Unit ------------Initalization----------------
	//UFUNCTION(BlueprintCallable)
	//void Initalize(ABattleTile* StartingLocation);

	//Unit ------------Gets/Sets----------------
	UFUNCTION(BlueprintCallable)
	int32 GetMovementPoints() { return MovementPoints; }
	UFUNCTION(BlueprintCallable)
	FString GetUnitName() { return UnitName; }
	UFUNCTION(BlueprintCallable)
	int32 GetCurrentHealth() { return CurrentHealth; }
	UFUNCTION(BlueprintCallable)
	int32 GetMaxHealth() { return MaxHealth; }


	//Unit ------------Combat----------------
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(int32 Amount);

	UFUNCTION(BlueprintCallable)
	int32 DealDamage();

	UFUNCTION(BlueprintCallable)
	void DefeatUnit();


	//Unit ------------Events----------------
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnUnitDefeated OnUnitDefeated;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMovementFinished OnMovementFinished;

	//Unit ------------Movement----------------
	//UFUNCTION(BlueprintCallable)
	//void MoveTo(FTransform Destination);

	//UFUNCTION(BlueprintCallable)
	void BeginMovement(TArray<FTransform> Path, FIntPoint EndCoords);

	//UFUNCTION(BlueprintCallable)
	//void MoveToTile(ABattleTile* Destination);

	//return the cost to move into a particular terrian type
	UFUNCTION(BlueprintCallable)
	int32 GetMovementCost(ETileTerrainType InTerrainType);

	//--------------

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	////Unit ------------Current Location------------
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Attribute")
	//ABattleTile* CurrentTile;

	//Unit ------------Movement----------------
	TArray<FTransform> CurrentPath;
	int32 CurrentPathIndex;
	FIntPoint MovementEndCoords;
	bool bMoving;
	FTransform CurrentDestination;


	//FTransform TargetDestination;
	//ABattleTile* TargetDestination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MoveSpeed = 300.0f;

	void UpdateMovement(float DeltaTime);
	void MovementComplete();
};
