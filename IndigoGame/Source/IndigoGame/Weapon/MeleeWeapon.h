// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BaseWeapon.h"
#include "MeleeWeapon.generated.h"


UCLASS()
class INDIGOGAME_API AMeleeWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UCapsuleComponent* Collision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
	FAttackInfo TopAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
	FAttackInfo DownAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
	FAttackInfo RightAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
	FAttackInfo LeftAttack;
	
	AMeleeWeapon();
	
};
