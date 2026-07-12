// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileShapeType.h"
#include "BattleTile.h"
#include "TileTerrainType.h"
#include "BattleGridManager.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API ABattleGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleGridManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	// creates a x by y grid based on SizeX and SizeY variables
	//void GenerateGrid();
	void GenerateGrid(int32 NewSizeX, int32 NewSizeY, TileShapeType TileShape);

	UFUNCTION(BlueprintCallable)
	//returns Tile at Coords
	ABattleTile* GetTileByCoords(int32 X, int32 Y) const;
	ABattleTile* GetTileByCoords(FIntPoint Coords) const { return GetTileByCoords(Coords.X, Coords.Y); }

	UFUNCTION(BlueprintCallable)
	//check if coords are in grid or not
	bool ValidCoordsInGrid(int32 X, int32 Y) const;
	bool ValidCoordsInGrid(FIntPoint Coords) const { return ValidCoordsInGrid(Coords.X, Coords.Y); }

	//Check if tile is valid in the grid
	UFUNCTION(BlueprintCallable)
	bool ValidTile(ABattleTile* Tile);

	//UFUNCTION(BlueprintCallable)
	////returns Tile at Coords
	//FTransform GetTileSpawnLocation(int32 X, int32 Y);

	UFUNCTION(BlueprintCallable)
	TArray<ABattleTile*> GetTileNeighbors(ABattleTile* Tile);

	UFUNCTION(BlueprintCallable)
	float GetDistanceBetweenTiles(ABattleTile* StartTile, ABattleTile* EndTile);

	UFUNCTION(BlueprintCallable)
	void ClearHighlightedTiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	int SizeX=2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	int SizeY=2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Grid")
	TileShapeType GridTileType = TileShapeType::Square;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	TArray <ABattleTile*> BattleGrid;

	UPROPERTY(EditAnywhere, Category = "Grid")
	TSubclassOf<ABattleTile> TileBPClass;

	//----- Grid Offset Arrays ------
	const TArray<FIntPoint> SquareOffsets =
	{
		{ 0,  1},
		{ 1,  0},
		{ 0, -1},
		{-1,  0}
	};

	//Pointed Hex
	const TArray<FIntPoint> OddRowOffsets =
	{
		{ 0,-1}, // NW
		{ 1,-1}, // NE
		{-1, 0}, // W
		{ 1, 0}, // E
		{ 0, 1}, // SW
		{ 1, 1}  // SE
	};

	const TArray<FIntPoint> EvenRowOffsets =
	{
		{-1,-1}, // NW
		{ 0,-1}, // NE
		{-1, 0}, // W
		{ 1, 0}, // E
		{-1, 1}, // SW
		{ 0, 1}  // SE
	};

	//Flat Hex
	const TArray<FIntPoint> OddColumnOffsets =
	{
		{-1, 0}, // NW
		{ 0,-1}, // NE
		{-1, 1}, // W
		{ 1, 1}, // E
		{ 0, 1}, // SW
		{ 1, 0}  // SE
	};

	const TArray<FIntPoint> EvenColumnOffsets =
	{
		{ 0,-1}, //N
		{ 0,+1}, //S
		{+1,-1}, //NE
		{+1, 0}, //SE
		{-1, 0}, //SW
		{-1,-1} //NW
	};



};
