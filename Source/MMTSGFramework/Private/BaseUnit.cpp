// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BaseUnit.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 ABaseUnit::GetMovementCost(ETileTerrainType)
{
	int32 MovementCost = 1;

	return MovementCost;
}

void ABaseUnit::ApplyDamage(int32 Amount)
{
	CurrentHealth -= Amount;
}

int32 ABaseUnit::DealDamage()
{
	//log attack infomration
	/*FString AttackMessage = FString::Printf(
		TEXT("%s attacks with power of %d"),
		UnitName,
		AttackPower
	);

	UE_LOG(LogTemp, Log, TEXT("%s"), AttackMessage);*/
	return AttackPower;
}

