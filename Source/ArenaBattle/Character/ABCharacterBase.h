// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacterBase();

protected:
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Customization")
	TMap<ECharacterControlType, class UABCharacterControlData*> CharacterControlManager;
//ComboAction
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Animation)
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Attack, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABComboActionData> ComboActionData;

	void ProcessComboCommand();

	void ComboActionBegin();
	void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);
	void SetComboCheckTimer();
	void ComboCheck();
	
	int32 CurrentCombo = 0;
	FTimerHandle ComboTimerHandle;
	bool HasNextComboCommand = false;
	//BodyParts
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Parts")
	TMap<FString, USkeletalMeshComponent*> CharacterPartsMap;
	virtual void BeginPlay() override;
	
	TMap<FString, TArray<TAssetPtr<USkeletalMesh>>> AvailableMeshesForParts;
	void InitializeAvailableBodyParts();

};