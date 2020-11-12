// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"


UENUM(BlueprintType)
enum class EAttackDirection : uint8
{
	Up,
	Down,
	Left,
	Right
};

USTRUCT(BlueprintType)
struct FAttackInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UAnimMontage* AnimMontage;

	/*режущий*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Cutting;

	/*колющий*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Piercing;

	/*дробящий*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Crushing;

	/*перелом*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Fracture;

	/*кровотечение*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Bleeding;

	/*пробитие*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Breaking;

};




USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	/*базовый урон*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BaseDamage;

	/*множитель урона в голову*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float HeadMultiplier;

	/*множитель урона в тело*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ChestMultiplier;

	/*множитель урона в руки*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float HandsMultiplier;

	/*множитель урона в ноги*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float LegsMultiplier;
};




UCLASS()
class INDIGOGAME_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
	FWeaponData WeaponData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
