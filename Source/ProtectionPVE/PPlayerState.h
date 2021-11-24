// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PPlayerState.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class PROTECTIONPVE_API APPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerScore(float NewScore);

	void SetScoreText(UTextBlock* Text);

	UFUNCTION()
	void CreateWeapon(int Slot, TSubclassOf<class APWeapon> WeaponClass, FName SocketName);

	UFUNCTION()
	TSubclassOf<APWeapon> GetWeaponClass(const FString& WeaponName);

	UFUNCTION()
	FName GetWeaponAttachSocketName(const FString& WeaponName);
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	UTextBlock* ScoreText;
};

