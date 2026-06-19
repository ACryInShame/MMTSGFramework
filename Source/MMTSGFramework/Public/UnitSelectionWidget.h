// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UnitSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMTSGFRAMEWORK_API UUnitSelectionWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateUnitInfo(ABaseUnit* NewUnit);

    UFUNCTION(BlueprintImplementableEvent)
    void ClearUnitInfo();
};
