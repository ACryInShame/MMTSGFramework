// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileShapeType.h"
#include "BattleTile.h"
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
	void GenerateGrid();

	UFUNCTION(BlueprintCallable)
	//returns Tile at Coords
	ABattleTile* GetTileByCoords(int32 X, int32 Y);

	UFUNCTION(BlueprintCallable)
	//check if coords are in grid or not
	bool ValidCoordsInGrid(int32 X, int32 Y);

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

};
