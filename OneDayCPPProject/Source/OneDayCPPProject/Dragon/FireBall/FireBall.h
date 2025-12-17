// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireBall.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API AFireBall : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USphereComponent> SphereComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UProjectileMovementComponent> ProjectileComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UNiagaraComponent> FireBallComp;
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UNiagaraSystem> HitEffect;
	UPROPERTY(VisibleAnywhere)
	FVector StartLocation;	
	UPROPERTY(EditAnywhere)
	float MaxDistance = 1200.f;

public:	
	// Sets default values for this actor's properties
	AFireBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
