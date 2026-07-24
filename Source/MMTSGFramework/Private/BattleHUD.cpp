// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BattleHUD.h"
#include <LocalPlayerController.h>

void UBattleHUD::ProcessActionCommand(ETacticalCommandType ButtonCommand)
{
    if (ControllingPlayer)
        ControllingPlayer->ProcessCommand(ButtonCommand);
    else
        UE_LOG(LogTemp, Warning, TEXT("ControllingPlayer is invalid"));
}
