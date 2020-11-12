// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeWeapon.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"


AMeleeWeapon::AMeleeWeapon()
{
	Collision = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	Collision->SetupAttachment(WeaponMesh);
}

UAnimMontage* AMeleeWeapon::GetAnimAttack(EAttackDirection AttackDirection) const
{
	switch (AttackDirection)
	{
	case EAttackDirection::Up:
		return UpAttack.AnimMontage;

	case EAttackDirection::Down:
		return DownAttack.AnimMontage;

	case EAttackDirection::Left:
		return LeftAttack.AnimMontage;
		
	case EAttackDirection::Right:
		return RightAttack.AnimMontage;
	}
	
	return nullptr;
}
