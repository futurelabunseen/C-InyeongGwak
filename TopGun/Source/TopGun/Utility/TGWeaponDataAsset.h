// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TGWeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class TOPGUN_API UTGWeaponDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Object)
	TMap<FName, UBlueprintGeneratedClass*> BaseWeaponClasses;
};