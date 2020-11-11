// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "HitBoxComponent.generated.h"

UENUM(BlueprintType)
enum class EBodyModule : uint8
{
	HeadModule,
	ChestModule,
	HandsModule,
	LegsModule
};

UENUM(BlueprintType)
enum class EBodySide : uint8
{
	None,
	Left,
	Right
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INDIGOGAME_API UHitBoxComponent : public UCapsuleComponent
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EBodyModule BodyModule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EBodySide BodySide;
	
};
