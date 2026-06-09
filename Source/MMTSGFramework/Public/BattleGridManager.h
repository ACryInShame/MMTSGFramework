// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileShapeType.h"
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

	//UFUNCTION()
	//void GenerateGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	int SizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Components")
	int SizeY;

};
