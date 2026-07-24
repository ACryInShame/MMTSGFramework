// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "BattleWidget.h"
#include <BattleHUD.h>
#include "ActionSelectionBarWidget.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API UActionSelectionBarWidget : public UBattleWidget
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    void SelectAction(ETacticalCommandType ButtonCommand);

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI", meta = (ExposeOnSpawn = "true"))
    UBattleHUD* ParentHUD;
};
