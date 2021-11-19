// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class PROTECTIONPVE_API APWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APWeapon();

	UFUNCTION()
	void Shoot();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NativeShoot();
	
	bool CheckAimHit(FHitResult& Hit) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	FName LeftHandIKSocketName;

	// Reference
	UPROPERTY()
	APlayerController* PC;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	class UParticleSystem* DefaultImpactEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	// UPROPERTY(EditDefaultsOnly, Category="Components")
	// USkeletalMeshComponent* MagazineMeshComp;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FName MagazineSocketName;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon")
	int RemainBulletCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	int MaxBulletCount;
};

