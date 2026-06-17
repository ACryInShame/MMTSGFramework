// CopyRight owned by Louis J D'Agusto, all rights reserved


#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Default Root Comp
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));

	//Set Camera SpringArm
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);

	// Create and set Camera
	CameraObject = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraObject->SetupAttachment(CameraSpringArm);

	//Default Values
	CameraMoveSpeed = 1000.0f; // Speed that camera moves around in Z and Y
	CamerRotationSpeed = 300.0f; // speed camera rotates around pawn
	CameraZoomIntervalSpeed = 100.0f; // the distance per 'tick' of zoom
	CameraZoomMin = 500.0f; // Min distance for boom arm to zoom
	CameraZoomMax = 3000.0f; // Max distance boom arm can zoom
	CameraAngle = -65.0f; // angel the boon arm is at from pawn

}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();

	//Set spring arm angle
	CameraSpringArm->SetRelativeRotation(
		FRotator(CameraAngle, 0.0f, 0.0f)
	);
	
}

void APlayerCamera::MoveCamera(FVector2D Input)
{
	//vector for flat camera movement
	FVector NewDirection = (GetActorForwardVector() * Input.Y) + (GetActorRightVector() * Input.X);

	SetActorLocation(
		GetActorLocation() +
		NewDirection * CameraMoveSpeed * GetWorld()->GetDeltaSeconds()
	);
}

void APlayerCamera::RotateCamera(float Input)
{
	// set rotation based on player input
	FRotator Rotation = GetActorRotation();

	Rotation.Yaw += Input * CamerRotationSpeed * GetWorld()->GetDeltaSeconds();

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
	float NewLength = CameraSpringArm->TargetArmLength - (Input * CameraZoomIntervalSpeed);

	//Set new Length
	CameraSpringArm->TargetArmLength = FMath::Clamp(	NewLength,
													CameraZoomMin,
													CameraZoomMax
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

