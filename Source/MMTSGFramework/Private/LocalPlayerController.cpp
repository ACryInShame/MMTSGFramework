// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "LocalPlayerController.h"

// Called when the game starts or when spawned
void ALocalPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //bEnableClickEvents = true;
    //bEnableMouseOverEvents = true;
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
        UE_LOG(
            LogTemp,
            Log,
            TEXT("Selected Unit: %s"),
            *NewSelectedUnit->GetName()
        );

        SelectUnit(NewSelectedUnit);

        ////update tile info based on where the unit is
        ABattleTile* NewSelectedTile = BattleManager->GetTileOfUnit(NewSelectedUnit);
        SelectTile(NewSelectedTile);

        BattleManager->HightlightMoveRange(NewSelectedUnit);
    }

    //if tile, update tile info
    if (ABattleTile* NewSelectedTile = Cast<ABattleTile>(Hit.GetActor()))
    {
        UE_LOG(
            LogTemp,
            Log,
            TEXT("Selected Tile: %s"),
            *NewSelectedTile->GetFName().ToString()
        );
    
        SelectTile(NewSelectedTile);
    
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
}

void ALocalPlayerController::ProcessCommand(ETacticalCommandType ButtonCommand)
{
    const UEnum* EnumPtr = StaticEnum<ETacticalCommandType>();

    FString CommandName = EnumPtr
        ? EnumPtr->GetNameStringByValue((int64)ButtonCommand)
        : TEXT("Invalid");

    UE_LOG(LogTemp, Warning, TEXT("Select Action Called: %s"), *CommandName);

}

void ALocalPlayerController::SelectUnit(ABaseUnit* NewTargetUnit)
{
    SelectedUnit = NewTargetUnit;
    UpdateUnitInfo(SelectedUnit);
}

void ALocalPlayerController::SelectTile(ABattleTile* NewTargetTile)
{
    SelectedTile = NewTargetTile;
    UpdateTileInfo(SelectedTile);
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
