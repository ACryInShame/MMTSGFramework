// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include <BattleWidget.h>
//#include <LocalPlayerController.h>
#include "CoreMinimal.h"
#include "BattleHUD.generated.h"

// forward declaration for flow of commands
class ALocalPlayerController;
/**
 * 
 */
UCLASS()
class MMTSGFRAMEWORK_API UBattleHUD : public UBattleWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void ProcessActionCommand(ETacticalCommandType ButtonCommand);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player", meta = (ExposeOnSpawn = "true"))
	ALocalPlayerController* ControllingPlayer;


};
