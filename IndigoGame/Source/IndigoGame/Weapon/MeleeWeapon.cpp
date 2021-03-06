// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeWeapon.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"


AMeleeWeapon::AMeleeWeapon()
{
	Collision = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	Collision->SetupAttachment(WeaponMesh);
}

UAnimMontage* AMeleeWeapon::GetAnimAttack(EAttackDirection AttackDirection)
{
	switch (AttackDirection)
	{
	case EAttackDirection::Up:
		LastAttack = UpAttack;
		return UpAttack.AnimMontage;

	case EAttackDirection::Down:
		LastAttack = DownAttack;
		return DownAttack.AnimMontage;

	case EAttackDirection::Left:
		LastAttack = LeftAttack;
		return LeftAttack.AnimMontage;
		
	case EAttackDirection::Right:
		LastAttack = RightAttack;
		return RightAttack.AnimMontage;
	}
	
	return nullptr;
}
