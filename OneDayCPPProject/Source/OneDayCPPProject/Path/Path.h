// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Path.generated.h"

UCLASS()
class ONEDAYCPPPROJECT_API APath : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USplineComponent> SplineComp;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABatMonster> FollowerActorClass;
	UPROPERTY(EditAnywhere)
	float SpawnIntervalMin = 2.0f;
	UPROPERTY(EditAnywhere)
	float SpawnIntervalMax = 5.0f;
	FTimerHandle SpawnTimerHandle;
public:	
	// Sets default values for this actor's properties
	APath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	USplineComponent* GetSplineComp() const { return SplineComp; }
	void SpawnFollowerActor();
	void SpawnTimerTick();
	bool CarculatePathLocation(float Distance,FVector& Location,FRotator& Rotation);

};
