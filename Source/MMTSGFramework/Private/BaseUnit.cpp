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
	SetActorTickEnabled(false);}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// update location for movement
	UpdateMovement(DeltaTime);

	//check it reached current target destination, if not continue moving
	if (GetActorLocation().Equals(CurrentDestination.GetLocation(), 1.f))
	{
		// update next index
		CurrentPathIndex++;

		//check if there are any destinations left in path
		if (CurrentPathIndex >= CurrentPath.Num())
		{
			//move complete
			MovementComplete();
		}
		else //if there is still some left, update to next destination
		{
			CurrentDestination = CurrentPath[CurrentPathIndex];
		}
	}

	//if (GetActorLocation().Equals(CurrentPath.Last().GetLocation()))
	//{
	//	SetActorTickEnabled(false);
	//	MovementComplete();
	//}
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

	if (CurrentHealth <= 0)
		DefeatUnit();
}

void ABaseUnit::DefeatUnit()
{
	OnUnitDefeated.Broadcast(this);
}

int32 ABaseUnit::DealDamage()
{
	return AttackPower;
}

void ABaseUnit::BeginMovement(const TArray<FTransform>& Path, FIntPoint EndCoords )
{
	//Check Input
	if (Path.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Path is Empty in ABaseUnit::BeginMovement"));
		return;
	}

	//setup path variables for tick movement
	CurrentPath = Path;
	CurrentPathIndex = 0;
	MovementEndCoords = EndCoords;
	bMoving = true;
	CurrentDestination = CurrentPath[0];

	SetActorTickEnabled(true);
}

void ABaseUnit::UpdateMovement(float DeltaTime)
{
	FVector NewLocation =
		FMath::VInterpConstantTo(
			GetActorLocation(),
			CurrentDestination.GetLocation(),
			DeltaTime,
			MoveSpeed
		);

	SetActorLocation(NewLocation);
}

void ABaseUnit::MovementComplete()
{
	SetActorTickEnabled(false);
	bMoving = false;

	OnMovementFinished.Broadcast(this, MovementEndCoords);
}