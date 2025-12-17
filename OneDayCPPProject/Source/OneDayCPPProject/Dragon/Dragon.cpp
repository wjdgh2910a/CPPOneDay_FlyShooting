// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon/Dragon.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Animation/AnimMontage.h"

// Sets default values
ADragon::ADragon()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UAnimMontage> DragonMeshAsset(TEXT("/Script/Engine.AnimMontage'/Game/Blueprints/Character/Animation/AM_Fire.AM_Fire'"));
	if(DragonMeshAsset.Succeeded())
	{
		FireMontage = DragonMeshAsset.Object;
	}
}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = MeshComp->GetAnimInstance();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ADragon::Fire, FireInterval, true, FireInterval);
}

// Called every frame
void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	NewLocation.X = FMath::Clamp(NewLocation.X, MoveBoundsMin.X, MoveBoundsMax.X);
	NewLocation.Y = FMath::Clamp(NewLocation.Y, MoveBoundsMin.Y, MoveBoundsMax.Y);
	SetActorLocation(NewLocation);
}

// Called to bind functionality to input
void ADragon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADragon::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	PlayerController = Cast<APlayerController>(NewController);
}

void ADragon::Fire()
{
	if (MeshComp && AnimInstance && FireMontage)
	{
			AnimInstance->Montage_Play(FireMontage);
			FVector FireLocation = MeshComp->GetSocketLocation(FName(TEXT("FireSocket")));
			GetWorld()->SpawnActor<AActor>(FireballClass, FireLocation, GetActorRotation());
	}
}

