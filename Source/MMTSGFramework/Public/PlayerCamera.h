// CopyRight owned by Louis J D'Agusto, all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCamera.generated.h"

UCLASS()
class MMTSGFRAMEWORK_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Take values from player input and move camera
	UFUNCTION(BlueprintCallable)
	void MoveCamera(FVector2D Input);

	UFUNCTION(BlueprintCallable)
	void RotateCamera(float Input);

	UFUNCTION(BlueprintCallable)
	void ZoomCamera(float Input);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* CameraSpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CamerRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraZoomIntervalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraZoomMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraZoomMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraAngle;

};
