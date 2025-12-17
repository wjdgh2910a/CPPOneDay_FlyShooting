// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlyingCreature/FlyingCreature.h"
#include "BatMonster.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API ABatMonster : public AFlyingCreature
{
	GENERATED_BODY()
private:
	TObjectPtr<class APath> FollowPath;
	float MoveSpeed = 200.0f;
	float MoveDistance = 0.0f;
	float FireInterval = 2.0f;
	FTimerHandle FireTimerHandle;
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

	void SetFollowPath(APath* NewPath) { FollowPath = NewPath; }
	void MoveSpline(float DeltaTime);
	void Fire();
};
