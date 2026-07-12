// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <BaseUnit.h>
#include "UnitManager.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API AUnitManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnitManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void DestroyUnit();

	UFUNCTION(BlueprintCallable)
	void GetUnitByID();

	UFUNCTION(BlueprintCallable)
	ABaseUnit* SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform UnitSpawnLocationTransform, FIntPoint GridCoords);

	UFUNCTION(BlueprintCallable)
	FIntPoint GetLocationOfUnit(ABaseUnit* TargetUnit);

	UFUNCTION(BlueprintCallable)
	void SetUnitLocation(ABaseUnit* TargetUnit, FIntPoint NewLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Units")
	TMap<ABaseUnit*, FIntPoint> Units;

	UFUNCTION(BlueprintCallable)
	void HandleUnitDefeated(ABaseUnit* DefeatedUnit);
};