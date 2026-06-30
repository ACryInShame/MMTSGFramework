// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "BaseUnit.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// update location for movement
	UpdateMovement(DeltaTime);

	if (GetActorLocation().Equals(TargetDestination->GetUnitAnchorTransform().GetLocation(),1.0f))
	{
		SetActorTickEnabled(false);
		MovementComplete();
	}
}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseUnit::Initalize(ABattleTile* StartingLocation)
{
	CurrentTile = StartingLocation;
}

int32 ABaseUnit::GetMovementCost(ETileTerrainType)
{
	int32 MovementCost = 1;

	return MovementCost;
}

void ABaseUnit::ApplyDamage(int32 Amount)
{
	CurrentHealth -= Amount;

	if (CurrentHealth <= 0)
		DefeatUnit();
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

void ABaseUnit::DefeatUnit()
{
	OnUnitDefeated.Broadcast(this);
}

//void ABaseUnit::MoveTo(FTransform Destination)
//{
//	SetActorTickEnabled(true);
//	TargetDestination = Destination;
//}

void ABaseUnit::MoveToTile(ABattleTile* Destination)
{
	SetActorTickEnabled(true);
	TargetDestination = Destination;
}

void ABaseUnit::UpdateMovement(float DeltaTime)
{
	if (!TargetDestination)
	{
		SetActorTickEnabled(false);
		return;
	}

	FVector NewLocation =
		FMath::VInterpConstantTo(
			GetActorLocation(),
			TargetDestination->GetUnitAnchorTransform().GetLocation(),
			DeltaTime,
			MoveSpeed
		);

	SetActorLocation(NewLocation);
}

void ABaseUnit::MovementComplete()
{
	//Snap unit to anchor point
	SetActorLocation( TargetDestination->GetUnitAnchorTransform().GetLocation() );

	//update unit and tile occupation information
	CurrentTile->SetOccupyingUnit(nullptr);
	CurrentTile = TargetDestination;
	TargetDestination = nullptr;
	CurrentTile->SetOccupyingUnit(this);
}
