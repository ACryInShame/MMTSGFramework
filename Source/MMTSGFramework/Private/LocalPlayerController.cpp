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

void ALocalPlayerController::HandlePlayerInput()
{
    switch (CommandMode)
    {
    case ETacticalCommandType::None:
        HandleSelect();
        break;
    case ETacticalCommandType::Move:
        HandleMoveSelect();
        break;

    case ETacticalCommandType::Attack:
        HandleAttackSelect();
        break;

    case ETacticalCommandType::Wait:
        HandleWaitSelect();
        break;

    default:
        break;
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
    BattleHUD->UpdateUnitInfo(Unit);
}

void ALocalPlayerController::UpdateTileInfo(ABattleTile* Tile)
{
    BattleHUD->UpdateTileInfo(Tile);
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
        if (!SelectedUnit->GetHasMoved())
            ProcessMoveCommand();
        else
            UE_LOG(LogTemp, Warning, TEXT("Unit Has already used the %s Command This Turn"), *CommandName);
        break;

    case ETacticalCommandType::Attack:
        if (!SelectedUnit->GetHasAttacked())
            ProcessAttackCommand();
        else
            UE_LOG(LogTemp, Warning, TEXT("Unit Has already used the %s Command This Turn"), *CommandName);
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
    CommandMode = ETacticalCommandType::None;
    BattleHUD->UpdateCommandMode(CommandMode);
}

void ALocalPlayerController::ProcessMoveCommand()
{
    //Change command to move highlight tiles
    CommandMode = ETacticalCommandType::Move;

    if (SelectedUnit)
        BattleManager->HightlightMoveRange(SelectedUnit);
    else
        UE_LOG(LogTemp, Error, TEXT("LocalPlayerController :: ProcessMoveCommand : SelectedUnit is invalid"));

    BattleHUD->UpdateCommandMode(CommandMode);
}

void ALocalPlayerController::ProcessAttackCommand()
{
    //Change command to attack highlight tiles
    CommandMode = ETacticalCommandType::Attack;

    if (SelectedUnit)
        BattleManager->HightlightAttackRange(SelectedUnit);
    else
        UE_LOG(LogTemp, Error, TEXT("LocalPlayerController :: ProcessAttackCommand : SelectedUnit is invalid"));

    BattleHUD->UpdateCommandMode(CommandMode);
}

void ALocalPlayerController::ProcessWaitCommand()
{
    CommandMode = ETacticalCommandType::None;
    SelectedUnit->SkipTurn();
    BattleHUD->UpdateCommandMode(CommandMode);
}

void ALocalPlayerController::HandleMoveSelect()
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

    //cannot select unit to move to
    if (ABaseUnit* NewSelectedUnit = Cast<ABaseUnit>(Hit.GetActor()))
    {
        UE_LOG(
            LogTemp,
            Log,
            TEXT("Unable to move to tile with Unit: %s"),
            *NewSelectedUnit->GetName()
        );
    }

    //select tile to move to
    if (ABattleTile* NewSelectedTile = Cast<ABattleTile>(Hit.GetActor()))
    {
        FTacticalCommand Command;
        Command.Type = ETacticalCommandType::Move;
        Command.SourceUnitID = SelectedUnit->GetUnitID();
        FIntPoint TileCoords(NewSelectedTile->GetGridX(), NewSelectedTile->GetGridY());
        Command.TargetCoords = TileCoords;

        if (BattleManager->ExecuteCommand(Command))
        {
            ProcessNoneCommand();
        }
    }
}

void ALocalPlayerController::HandleAttackSelect()
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

    ABattleTile* NewSelectedTile = nullptr;

    //If unit seelcted translate Unit selection to Tile
    if (ABaseUnit* NewSelectedUnit = Cast<ABaseUnit>(Hit.GetActor()))
    {
        if (NewSelectedUnit)
        {
            NewSelectedTile = BattleManager->GetTileOfUnit(NewSelectedUnit);
            UE_LOG(LogTemp, Warning, TEXT("ALocalPlayerController::HandleAttackSelect unit selected"));

        }
        else
            UE_LOG(LogTemp, Warning, TEXT("ALocalPlayerController::HandleAttackSelect no unit selected"));

    }

    //Select Tile to attack
    if (!NewSelectedTile)
    {
        NewSelectedTile = Cast<ABattleTile>(Hit.GetActor());
        UE_LOG(LogTemp, Warning, TEXT("ALocalPlayerController::HandleAttackSelect Tile selected"));
    }

    //check for valid tile and then process attack
    if (NewSelectedTile)
    {
        UE_LOG(LogTemp, Warning, TEXT("ALocalPlayerController::HandleAttackSelect attack command given"));
        FTacticalCommand Command;
        Command.Type = ETacticalCommandType::Attack;
        Command.SourceUnitID = SelectedUnit->GetUnitID();
        FIntPoint TileCoords(NewSelectedTile->GetGridX(), NewSelectedTile->GetGridY());
        Command.TargetCoords = TileCoords;

        if (BattleManager->ExecuteCommand(Command))
        {
            ProcessNoneCommand();
        }
        else
            UE_LOG(LogTemp, Error, TEXT("ALocalPlayerController::HandleAttackSelect attack command failed"));
    }
    else
        UE_LOG(LogTemp, Error, TEXT("ALocalPlayerController::HandleAttackSelect no Tile selected"));


}

void ALocalPlayerController::HandleWaitSelect()
{
    if (!SelectedUnit->GetHasMoved() || !SelectedUnit->GetHasAttacked())
    {
        ProcessCommand(ETacticalCommandType::Wait);
    }
    else
        UE_LOG(LogTemp, Warning, TEXT("ALocalPlayerController::HandleWaitSelect Unit already done turn"));

}

void ALocalPlayerController::EndTurnActions()
{
    BattleManager->EndTurn();
}
