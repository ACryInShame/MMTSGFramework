// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "TacticalCommands.h"
#include "Blueprint/UserWidget.h"
#include "BaseUnit.h"
#include "BattleTile.h"
#include "BattleWidget.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API UBattleWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateUnitInfo(ABaseUnit* Unit);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateTileInfo(ABattleTile* Tile);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateTurn();
};
