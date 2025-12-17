// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingCreature/FlyingCreature.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AFlyingCreature::AFlyingCreature()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SetRootComponent(SphereComp);
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(SphereComp);
}

// Called when the game starts or when spawned
void AFlyingCreature::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyingCreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlyingCreature::Hit()
{
	HP -= 1;
	if (HP <= 0)
	{
		Destroy();
	}
}

