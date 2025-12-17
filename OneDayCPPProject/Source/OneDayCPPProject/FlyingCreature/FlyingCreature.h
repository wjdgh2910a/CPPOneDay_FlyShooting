// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FlyingCreature.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API AFlyingCreature : public APawn
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> FireballClass;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USphereComponent> SphereComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USkeletalMeshComponent> MeshComp;
	UPROPERTY(EditAnywhere)
	int HP = 1;
public:	
	// Sets default values for this actor's properties
	AFlyingCreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Hit();
};
