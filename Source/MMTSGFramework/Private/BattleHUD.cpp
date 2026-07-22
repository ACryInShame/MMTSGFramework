// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BattleHUD.h"

void UBattleHUD::ProcessActionCommand(ETacticalCommandType ButtonCommand)
{
    OwningPlayer->ProcessCommand(ButtonCommand);
}
