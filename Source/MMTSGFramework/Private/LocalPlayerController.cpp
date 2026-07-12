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
        if (SelectedUnit)
        {
            BattleManager->MoveCommand(SelectedUnit, NewSelectedTile);
        }
    }
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
    UnitSelectionWidget->UpdateUnitInfo(Unit);
}

void ALocalPlayerController::UpdateTileInfo(ABattleTile* Tile)
{
    TileSelectionWidget->UpdateTileInfo(Tile);
}
