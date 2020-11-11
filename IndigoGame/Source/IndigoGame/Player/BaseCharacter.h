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

	/*HeadBoxes*/
	/*HeadHitBox*/
	UPROPERTY(EditDefaultsOnly, Category="HitBoxes")
	class UHitBoxComponent* HeadHitBox;

	/*ChestHitBox*/
	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* ChestUHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* ChestDHitBox;

	/*LeftHandHitBox*/
	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftHandUHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftHandMHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftHandDHitBox;

	/*RightHandHitBox*/
	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightHandUHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightHandMHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightHandDHitBox;

	/*LeftLegHitBox*/
	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftLegUHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftLegMHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* LeftLegDHitBox;

	/*RightLegHitBox*/
	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightLegUHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightLegMHitBox;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxes")
	class UHitBoxComponent* RightLegDHitBox;


public:
	ABaseCharacter();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnAttack();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void Turn(float Axis);
	void LookUp(float Axis);

	void Attack();

};
