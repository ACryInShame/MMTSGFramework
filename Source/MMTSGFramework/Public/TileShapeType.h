// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"

//Enum for Tile Type
UENUM(BlueprintType)
enum class TileShapeType : uint8
{
    Square UMETA(DisplayName = "Square"),
    HexFlatTop UMETA(DisplayName = "Hex Flat Top"),
    HexPointedTop UMETA(DisplayName = "Hex Pointed Top")
};
