// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <string>
#include <TileTerrainType.h>
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
	int64 GetMovementCost(ETileTerrainType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY (EditAnywhere)
	FString UnitName;

	UPROPERTY(EditAnywhere)
	int64 CurrentHealth, MaxHealth;

	UPROPERTY(EditAnywhere)
	int64 AttackPower, DefencePoints;

	UPROPERTY(EditAnywhere)
	int64 MovementPoints;

	UPROPERTY(EditAnywhere)
	TMap<ETileTerrainType, int32>


};
