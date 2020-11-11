// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "HitBox/HitBoxComponent.h"
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

	HeadHitBox = CreateDefaultSubobject<UHitBoxComponent>("HeadHitBox");
	HeadHitBox->SetupAttachment(GetMesh(), FName("HeadHBSocket"));

	ChestUHitBox = CreateDefaultSubobject<UHitBoxComponent>("ChestUHitBox");
	ChestUHitBox->SetupAttachment(GetMesh(), FName("ChestUHBSocket"));

	ChestDHitBox = CreateDefaultSubobject<UHitBoxComponent>("ChestDHitBox");
	ChestDHitBox->SetupAttachment(GetMesh(), FName("ChestDHBSocket"));

	LeftHandUHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftHandUHitBox");
	LeftHandUHitBox->SetupAttachment(GetMesh(), FName("LeftHandUHBSocket"));

	LeftHandMHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftHandMHitBox");
	LeftHandMHitBox->SetupAttachment(GetMesh(), FName("LeftHandMHBSocket"));

	LeftHandDHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftHandDHitBox");
	LeftHandDHitBox->SetupAttachment(GetMesh(), FName("LeftHandDHBSocket"));

	RightHandUHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightHandUHitBox");
	RightHandUHitBox->SetupAttachment(GetMesh(), FName("RightHandUHBSocket"));

	RightHandMHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightHandMHitBox");
	RightHandMHitBox->SetupAttachment(GetMesh(), FName("RightHandMHBSocket"));

	RightHandDHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightHandDHitBox");
	RightHandDHitBox->SetupAttachment(GetMesh(), FName("RightHandDHBSocket"));

	LeftLegUHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftLegUHitBox");
	LeftLegUHitBox->SetupAttachment(GetMesh(), FName("LeftLegUHBSocket"));

	LeftLegMHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftLegMHitBox");
	LeftLegMHitBox->SetupAttachment(GetMesh(), FName("LeftLegMHBSocket"));

	LeftLegDHitBox = CreateDefaultSubobject<UHitBoxComponent>("LeftLegDHitBox");
	LeftLegDHitBox->SetupAttachment(GetMesh(), FName("LeftLegDHBSocket"));

	RightLegUHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightLegUHitBox");
	RightLegUHitBox->SetupAttachment(GetMesh(), FName("RightLegUHBSocket"));

	RightLegMHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightLegMHitBox");
	RightLegMHitBox->SetupAttachment(GetMesh(), FName("RightLegMHBSocket"));

	RightLegDHitBox = CreateDefaultSubobject<UHitBoxComponent>("RightLegDHitBox");
	RightLegDHitBox->SetupAttachment(GetMesh(), FName("RightLegDHBSocket"));


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

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ABaseCharacter::Attack);

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

void ABaseCharacter::Attack()
{
	OnAttack();
}
