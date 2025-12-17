// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Dragon.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API ADragon : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADragon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	void Fire();
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class APlayerController> PlayerController;
	UPROPERTY(EditAnywhere, Category = "Movement Bounds")
	FVector2D MoveBoundsMin;
	UPROPERTY(EditAnywhere, Category = "Movement Bounds")
	FVector2D MoveBoundsMax;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USphereComponent> SphereComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USkeletalMeshComponent> MeshComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAnimMontage> FireMontage;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> FireballClass;

	TObjectPtr<class UAnimInstance> AnimInstance;
};
