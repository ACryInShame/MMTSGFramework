// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleTile.generated.h"

//Enum for Tile Type
UENUM(BlueprintType)
enum class TileShapes : uint8
{
	Square,
	HexFlatTop,
	HexPointedTop
};

UCLASS()
class MMTSGFRAMEWORK_API ABattleTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleTile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateStaticMesh();

	//override of UE constructor
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	TileShapes TileShape;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridY = 0;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* SquareMesh;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* FlatHexMesh;

	UPROPERTY(EditDefaultsOnly, Category = "TileTypes")
	UStaticMesh* PointedHexMesh;

};
