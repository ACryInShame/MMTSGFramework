// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "LocalPlayerController.h"
#include "UnitSelectionWidget.h"

// Called when the game starts or when spawned
void ALocalPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //bEnableClickEvents = true;
    //bEnableMouseOverEvents = true;

    CommandMode = ETacticalCommandType::None;
}

void ALocalPlayerController::HandleSelect()
{
    //Get selected actor
    FHitResult Hit;

    bool bHit = GetHitResultUnderCursor(
        ECollisionChannel::ECC_Visibility,
        false,
        Hit
    );

    if (!bHit)
    {
        return;
    }

    //update unit info if selected a unit
    if (ABaseUnit* NewSelectedUnit = Cast<ABaseUnit>(Hit.GetActor()))
    {
            SelectUnit(NewSelectedUnit);
    }

    //if tile, update tile info
    if (ABattleTile* NewSelectedTile = Cast<ABattleTile>(Hit.GetActor()))
    { 
            SelectTile(NewSelectedTile);
    }
}

void ALocalPlayerController::SelectUnit(ABaseUnit* NewTargetUnit)
{
    if (NewTargetUnit != SelectedUnit)
    {
        SelectedUnit = NewTargetUnit;
        UpdateUnitInfo(SelectedUnit);

        if (NewTargetUnit)
        {
            UE_LOG(
                LogTemp,
                Log,
                TEXT("Selected Unit: %s"),
                *SelectedUnit->GetName()
            );
        }
        else
        {
            UE_LOG(
                LogTemp,
                Log,
                TEXT("Selected Unit: Null")
            );
        }
    }

    //check for null after as nullptr for unit is a valid possibility for unit selection.
    if (!NewTargetUnit)
        return;

    //update tile info based on where the unit is
    ABattleTile* NewSelectedTile = BattleManager->GetTileOfUnit(SelectedUnit);

    //check if Tile is already selected to prevent loop
    if (NewSelectedTile != SelectedTile && NewSelectedTile)
        SelectTile(NewSelectedTile);

    //BattleManager->HightlightMoveRange(SelectedUnit);
}

void ALocalPlayerController::SelectTile(ABattleTile* NewTargetTile)
{
    if (!NewTargetTile)
        return;

    if (NewTargetTile != SelectedTile)
    {
        SelectedTile = NewTargetTile;
        UpdateTileInfo(SelectedTile);

        if (NewTargetTile)
        {
            UE_LOG(
                LogTemp,
                Log,
                TEXT("Selected Tile: %s"),
                *SelectedTile->GetFName().ToString()
            );
        }
        else
        {
            UE_LOG(
                LogTemp,
                Log,
                TEXT("Selected Tile: Null")
            );
        }
    }

    //update Unit info based on Occupying Unit
    FIntPoint Coords(SelectedTile->GetGridX(), SelectedTile->GetGridY());
    ABaseUnit* NewTargetUnit = BattleManager->GetUnitByCoords(Coords);

    //Check if unit is already selected to prevent loop (nullptrs allowed for units)
    if (NewTargetUnit != SelectedUnit)
        SelectUnit(NewTargetUnit);

}

void ALocalPlayerController::UpdateUnitInfo(ABaseUnit* Unit)
{
    for (UBattleWidget* Widget : HUDWidgets)
    {
        Widget->UpdateUnitInfo(Unit);
    }
}

void ALocalPlayerController::UpdateTileInfo(ABattleTile* Tile)
{
    for (UBattleWidget* Widget : HUDWidgets)
    {
        Widget->UpdateTileInfo(Tile);
    }
}

void ALocalPlayerController::ProcessCommand(ETacticalCommandType ButtonCommand)
{
    const UEnum* EnumPtr = StaticEnum<ETacticalCommandType>();

    FString CommandName = EnumPtr
        ? EnumPtr->GetNameStringByValue((int64)ButtonCommand)
        : TEXT("Invalid");

    UE_LOG(LogTemp, Warning, TEXT("Player controller Select Action Called: %s"), *CommandName);


    switch (ButtonCommand)
    {
    case ETacticalCommandType::None:
        ProcessNoneCommand();
        break;
    case ETacticalCommandType::Move:
        ProcessMoveCommand();
        break;

    case ETacticalCommandType::Attack:
        ProcessAttackCommand();
        break;

    case ETacticalCommandType::Wait:
        ProcessWaitCommand();
        break;

    default:
        break;
    }
}

void ALocalPlayerController::ProcessNoneCommand()
{
}

void ALocalPlayerController::ProcessMoveCommand()
{
    //Temp gives command to move unit if unit is already slected
    // will refactor that a button press on menu is requires to issue commands (in combat phase of development)
    //if (SelectedUnit)
    //{
    //    FTacticalCommand Command;
    //    Command.Type = ETacticalCommandType::Move;
    //    Command.SourceUnitID = SelectedUnit->GetUnitID();
    //    FIntPoint TileCoords(NewSelectedTile->GetGridX(), NewSelectedTile->GetGridY());
    //    Command.TargetCoords = TileCoords;

    //    BattleManager->ExecuteCommand(Command);
    //    //BattleManager->MoveCommand(SelectedUnit, NewSelectedTile);
    //}
}

void ALocalPlayerController::ProcessAttackCommand()
{
}

void ALocalPlayerController::ProcessWaitCommand()
{
}