// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class INDIGOGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Camera")
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, Category="Camera")
	class UCameraComponent* TPCamera;

	UPROPERTY(EditAnywhere, Category="Settings")
	float Sensitivity;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void Turn(float Axis);
	void LookUp(float Axis);

};
