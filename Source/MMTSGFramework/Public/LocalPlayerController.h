// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <BaseUnit.h>
#include <UnitSelectionWidget.h>
#include <TileSelectionWidget.h>
#include "LocalPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class MMTSGFRAMEWORK_API ALocalPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void HandleMouseClick();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	//UFUNCTION(BlueprintCallable)
	//void ClearTargetSelection();
	
};
