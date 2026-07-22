// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "ActionSelectionBarWidget.h"

void UActionSelectionBarWidget::SelectAction(ETacticalCommandType ButtonCommand)
{
    ParentHUD->ProcessActionCommand(ButtonCommand);
}
