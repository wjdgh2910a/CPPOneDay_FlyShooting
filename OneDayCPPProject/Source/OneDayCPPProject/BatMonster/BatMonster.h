// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BatMonster.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API ABatMonster : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USphereComponent> SphereComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USkeletalMeshComponent> MeshComp;
public:
	// Sets default values for this pawn's properties
	ABatMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
