// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeWeapon.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"


AMeleeWeapon::AMeleeWeapon()
{
	Collision = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	Collision->SetupAttachment(WeaponMesh);
}
