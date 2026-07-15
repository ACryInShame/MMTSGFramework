// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "TacticalCommands.generated.h"

UENUM(BlueprintType)
enum class ETacticalCommandType : uint8
{
    None,
    Move,
    Attack,
    Wait
};

USTRUCT(BlueprintType)
struct FTacticalCommand
{
    GENERATED_BODY();

    UPROPERTY()
    ETacticalCommandType Type = ETacticalCommandType::None;

    UPROPERTY()
    int32  SourceUnitID = -1;

    UPROPERTY()
    FIntPoint TargetCoords = FIntPoint(-1, -1);
};
