// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Camera SpringArm
	CameraSpringArm =
		CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));

	// Create Cmaera
	CameraObject = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//attach Camera
	CameraObject->SetupAttachment(CameraSpringArm);
}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCamera::MoveCamera(FVector2D Input)
{
	//vector for flat camera movement
	FVector NewLocation = GetActorLocation();

	//Will move Camera Pawn along X and Y axsis
	NewLocation.X += Input.Y * 10.0f;
	NewLocation.Y += Input.X * 10.0f;

	SetActorLocation(NewLocation);
}

void APlayerCamera::RotateCamera(float Input)
{
	// set rotation based on player input
	FRotator Rotation = GetActorRotation();

	Rotation.Yaw += Input * 50.0f * GetWorld()->GetDeltaSeconds();

	SetActorRotation(Rotation);
}

void APlayerCamera::ZoomCamera(float Input)
{
	// check to ensuer camera arm is assigned properly
	if (!CameraSpringArm)
	{
		UE_LOG(LogTemp, Error, TEXT("CameraSpringArm is null"));
		return;
	}

	// Get New Length
	float NewLength = CameraSpringArm->TargetArmLength - (Input * 100.0f);

	//Set new Length
	CameraSpringArm->TargetArmLength = FMath::Clamp(	NewLength,
												500.0f,
												3000.0f
											);
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

