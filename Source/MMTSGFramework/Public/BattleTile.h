// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileShapeType.h"
#include "BattleTile.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API ABattleTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleTile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetTileShapeType(TileShapeType NewTileShapeType) { TileShape = NewTileShapeType; }
	void SetGridX(int32 NewGridX) { GridX = NewGridX; }
	void SetGridY(int32 NewGridY) { GridY = NewGridY; }

	TileShapeType GetTileShapeType() { return TileShape; }
	int32 GetGridX() { return GridX; }
	int32 GetGridY() { return GridY; }
	UStaticMeshComponent* GetTileMesh() {return TileMesh;};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateStaticMesh();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	TileShapeType TileShape;

	//override of UE constructor
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridX = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridY = 0;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* SquareMesh;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* FlatHexMesh;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* PointedHexMesh;

};
