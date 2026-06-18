// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TileTerrainType.h"
#include "BattleTile.h"
#include "BaseUnit.generated.h"

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

	//return the cost to move into a particular terrian type
	UFUNCTION(BlueprintCallable)
	int32 GetMovementCost(ETileTerrainType InTerrainType);

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int32 Amount);

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

	//Unit Current Location
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	ABattleTile* CurrentTile;

};
