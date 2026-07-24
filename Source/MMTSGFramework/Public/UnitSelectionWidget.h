// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include <BattleWidget.h>
#include "UnitSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMTSGFRAMEWORK_API UUnitSelectionWidget : public UBattleWidget
{
	GENERATED_BODY()
	
public:

    void UpdateUnitInfo(ABaseUnit* NewUnit);

    UFUNCTION(BlueprintImplementableEvent)
    void ClearUnitInfo();
};
