// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileShapeType.h"
#include "TileTerrainType.h"
#include "ETileHighlightState.h"
#include "BattleTile.generated.h"

class ABaseUnit; //Forward delaration to prevent circle declaration (as BaseUnit #includes this header)

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
	void SetTerrainType(ETileTerrainType NewTerrain) { TerrainType = NewTerrain; }
	void SetOccupyingUnit(ABaseUnit* NewUnit) { OccupyingUnit = NewUnit; }
	UFUNCTION(BlueprintCallable)
	void SetHighlightState(ETileHighlightState NewState) { HighLightState = NewState; UpdateMaterial(); }

	TileShapeType GetTileShapeType() const  { return TileShape; }
	int32 GetGridX() const  { return GridX; }
	int32 GetGridY() const { return GridY; }
	UStaticMeshComponent* GetTileMesh() const {return TileMesh;};
	ETileTerrainType GetTerrainType() const { return TerrainType; }
	ABaseUnit* GetOccupyingUnit() const { return OccupyingUnit; }

	UFUNCTION(BlueprintCallable)
	FTransform GetUnitAnchorTransform() const;

	//may change terrain data into a struct later
	UFUNCTION(BlueprintCallable)
	FString GetTerrainName() const;

	UFUNCTION(BlueprintCallable)
	FLinearColor GetTerrainColor() const;

	UFUNCTION(BlueprintCallable)
	void ClearHighlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateStaticMesh();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	ETileTerrainType TerrainType = ETileTerrainType::Grass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Attributes")
	TileShapeType TileShape;

	//override of UE constructor
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Occupancy")
	ABaseUnit* OccupyingUnit = nullptr;

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

	UFUNCTION(BlueprintCallable, Category = "Highlights")
	void UpdateMaterial();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Highlights")
	ETileHighlightState HighLightState;

};
