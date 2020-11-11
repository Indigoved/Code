// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapon/BaseWeapon.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sensitivity = 1.f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 500.f;

	TPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	TPCamera->SetupAttachment(SpringArm, SpringArm->GetAttachSocketName());
	TPCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::LookUp);
}


void ABaseCharacter::MoveForward(float Axis)
{
	if(Axis != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Axis);
	}
}

void ABaseCharacter::MoveRight(float Axis)
{
	if(Axis != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Axis);
	}
}

void ABaseCharacter::Turn(float Axis)
{
	if(Axis != 0.f)
	{
		Axis = Axis * Sensitivity * GetWorld()->GetDeltaSeconds();

		AddControllerYawInput(Axis);
	}
}

void ABaseCharacter::LookUp(float Axis)
{
	if(Axis != 0.f)
	{
		Axis = Axis * Sensitivity * GetWorld()->GetDeltaSeconds();

		AddControllerPitchInput(Axis);
	}
}