// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "LocalPlayerController.h"

// Called when the game starts or when spawned
void ALocalPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //bEnableClickEvents = true;
    //bEnableMouseOverEvents = true;
}

void ALocalPlayerController::HandleMouseClick()
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

    if (ABaseUnit* NewSelectedUnit = Cast<ABaseUnit>(Hit.GetActor()))
    {
        UE_LOG(
            LogTemp,
            Log,
            TEXT("Selected Unit: %s"),
            *NewSelectedUnit->GetName()
        );

        SelectUnit(NewSelectedUnit);

        ABattleTile* NewSelectedTile = NewSelectedUnit->GetCurrentTile();

        UE_LOG(
            LogTemp,
            Log,
            TEXT("Selected Tile: %s"),
            *NewSelectedTile->GetFName().ToString()
        );

        SelectTile(NewSelectedUnit->GetCurrentTile());
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

        if (SelectedUnit)
        {
            SelectedUnit->MoveToTile(NewSelectedTile);
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
