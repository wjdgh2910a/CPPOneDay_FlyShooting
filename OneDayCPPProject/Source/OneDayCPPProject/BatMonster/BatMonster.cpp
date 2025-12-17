// Fill out your copyright notice in the Description page of Project Settings.


#include "BatMonster/BatMonster.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Path/Path.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABatMonster::ABatMonster()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABatMonster::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ABatMonster::Fire, FireInterval, true, FireInterval);
}

// Called every frame
void ABatMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveSpline(DeltaTime);
}

// Called to bind functionality to input
void ABatMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABatMonster::MoveSpline(float DeltaTime)
{
	if(FollowPath == nullptr) { return; }
	MoveDistance += MoveSpeed * DeltaTime;
	FVector NewLocation;
	FRotator NewRotation;
	if (FollowPath->CarculatePathLocation(MoveDistance, NewLocation, NewRotation))
	{
		SetActorLocation(NewLocation);
		SetActorRotation(NewRotation);
	}
	else
	{
		Destroy();
	}
}

void ABatMonster::Fire()
{
	if (FireballClass == nullptr) return;
	APawn* MyCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (MyCharacter)
	{
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MyCharacter->GetActorLocation());
		AActor* Bullet = GetWorld()->SpawnActor<AActor>(FireballClass, GetActorLocation(), LookAtRotation);
	}

}

