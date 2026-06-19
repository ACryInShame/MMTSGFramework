// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TileSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMTSGFRAMEWORK_API UTileSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateTileInfo(ABattleTile* Tile);

    UFUNCTION(BlueprintImplementableEvent)
    void ClearTileInfo();
};
