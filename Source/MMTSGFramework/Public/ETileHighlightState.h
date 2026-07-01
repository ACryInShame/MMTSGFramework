// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ETileHighlightState : uint8
{
    None        UMETA(DisplayName = "None"),
    Selected    UMETA(DisplayName = "Selected"),
    Hover       UMETA(DisplayName = "Hover"),
    MoveRange   UMETA(DisplayName = "Move Range"),
    AttackRange UMETA(DisplayName = "Attack Range"),
    Path        UMETA(DisplayName = "Path")
};
