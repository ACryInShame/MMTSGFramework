// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "ActionSelectionBarWidget.h"

void UActionSelectionBarWidget::SelectAction(ETacticalCommandType ButtonCommand)
{
    if (ParentHUD)
        ParentHUD->ProcessActionCommand(ButtonCommand);
    else
        UE_LOG(LogTemp, Warning, TEXT("ParentHUD is invalid"));
}
