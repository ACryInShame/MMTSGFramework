// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <BaseUnit.h>
#include <BattleGridManager.h>
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
	ABaseUnit* SpawnUnitOnGridByCoords(TSubclassOf<ABaseUnit> UnitClass, int32 GridX, int32 GridY);

	//RegisterUnit()
	//UnregisterUnit()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Units")
	TArray<ABaseUnit*> Units;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Grid")
	ABattleGridManager* BattleGrid;

	//UFUNCTION(BlueprintCallable)
	//ABaseUnit* SpawnUnit(TSubclassOf<ABaseUnit> UnitClass, FTransform SpawnTransform);

	UFUNCTION(BlueprintCallable)
	void HandleUnitDefeated(ABaseUnit* DefeatedUnit);
};