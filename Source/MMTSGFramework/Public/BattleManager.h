// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleGridManager.h"
#include "UnitManager.h"
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
	//-----------------------

	UFUNCTION(BlueprintCallable)
	ABaseUnit* SpawnUnitOnGridByCoords(TSubclassOf<ABaseUnit> UnitClass, int32 CoordsX, int32 CoordsY);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void initialization();

	//Manager Variables
	UPROPERTY() //To prevent Unreal Engine Garbage colltion from accidently removing it
	ABattleGridManager* BattleGrid = nullptr;
	UPROPERTY() //To prevent Unreal Engine Garbage colltion from accidently removing it
	AUnitManager* UnitManager = nullptr;

	UPROPERTY(EditAnywhere, Category = "Managers")
	TSubclassOf<ABattleGridManager> BattleGridBlueprint;

	UPROPERTY(EditAnywhere, Category = "Managers")
	TSubclassOf<AUnitManager> UnitManagerBlueprint;
};
