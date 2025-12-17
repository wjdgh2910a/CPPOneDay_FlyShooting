// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon/FireBall/FireBall.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraComponent.h"

// Sets default values
AFireBall::AFireBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SetRootComponent(SphereComp);

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileComp->InitialSpeed = 800.f;
	ProjectileComp->MaxSpeed = 800.f;
	ProjectileComp->ProjectileGravityScale = 0.f;
	ProjectileComp->SetUpdatedComponent(SphereComp);

	FireBallComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("FireBallComp"));
	FireBallComp->SetupAttachment(SphereComp);
}

// Called when the game starts or when spawned
void AFireBall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFireBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

