// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <BaseUnit.h>
#include <UnitSelectionWidget.h>
#include <TileSelectionWidget.h>
#include <BattleManager.h>
#include <TacticalCommands.h>
#include "LocalPlayerController.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API ALocalPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void HandleSelect();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*realized that outside of MVP,
	BattleManager wont exist in menus so will need to create a parent base ‘GameManager’ class
	to work with different game states but all share a ‘handle click’ function.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Managers")
	ABattleManager* BattleManager;

	//--- Selections ----
	UFUNCTION(BlueprintCallable)
	void SelectUnit(ABaseUnit* NewTargetUnit);

	UFUNCTION(BlueprintCallable)
	void SelectTile(ABattleTile* NewTargetTile);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Selection")
	ABaseUnit* SelectedUnit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Selection")
	ABattleTile* SelectedTile;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Selection")
	UUnitSelectionWidget* UnitSelectionWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Selection")
	UTileSelectionWidget* TileSelectionWidget;

	//UFUNCTION(BlueprintCallable)
	void UpdateUnitInfo(ABaseUnit* Unit);

	//UFUNCTION(BlueprintCallable)
	void UpdateTileInfo(ABattleTile* Tile);

};
