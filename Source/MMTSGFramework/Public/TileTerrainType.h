// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ETileTerrainType : uint8
{
    Grass,
    Dirt,
    Sand,
    Water,
    Forest,
    Mountain,

    MAX UMETA(Hidden)
};
