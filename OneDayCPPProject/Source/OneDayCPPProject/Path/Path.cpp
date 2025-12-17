// Fill out your copyright notice in the Description page of Project Settings.


#include "Path/Path.h"
#include "Components/SplineComponent.h"
#include "BatMonster/BatMonster.h"

// Sets default values
APath::APath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SplineComp = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	SetRootComponent(SplineComp);
}

// Called when the game starts or when spawned
void APath::BeginPlay()
{
	Super::BeginPlay();
	SpawnTimerTick();
	
}

// Called every frame
void APath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APath::SpawnFollowerActor()
{
	if (FollowerActorClass == nullptr) return;
	ABatMonster* BatMonster = GetWorld()->SpawnActor<ABatMonster>(FollowerActorClass, GetActorLocation(), GetActorRotation());
	BatMonster->SetFollowPath(this);
}

void APath::SpawnTimerTick()
{
	float RandomInterval = FMath::FRandRange(SpawnIntervalMin, SpawnIntervalMax);
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &APath::SpawnTimerTick, RandomInterval,false);
	SpawnFollowerActor();
}

bool APath::CarculatePathLocation(float Distance, FVector& Location, FRotator& Rotation)
{
	if (Distance > SplineComp->GetSplineLength())
	{
		return false;
	}

	Location = SplineComp->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	Rotation = SplineComp->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	return true;
}