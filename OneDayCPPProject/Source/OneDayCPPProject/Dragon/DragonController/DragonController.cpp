// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon/DragonController/DragonController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Dragon/Dragon.h"

ADragonController::ADragonController()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextFinder(TEXT(
		"/Script/EnhancedInput.InputMappingContext'/Game/Blueprints/Character/Input/IMC_Dragon.IMC_Dragon'"));
	if (InputMappingContextFinder.Succeeded())
	{
		MappingContext = InputMappingContextFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/Character/Input/IA_Move.IA_Move'"));
	if (MoveActionFinder.Succeeded())
	{
		MoveAction = MoveActionFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> FireActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/Character/Input/IA_FireBall.IA_FireBall'"));
	if (FireActionFinder.Succeeded())
	{
		FireAction = FireActionFinder.Object;
	}
}

void ADragonController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* InputSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSystem != nullptr)
	{
		InputSystem->AddMappingContext(MappingContext, 0);
	}
}

void ADragonController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADragonController::MoveInput);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &ADragonController::FireInput);
	}
}

void ADragonController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	ControlledDragon = Cast<ADragon>(aPawn);
}

void ADragonController::MoveInput(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (ControlledDragon)
	{
		ControlledDragon->AddMovementInput(ControlledDragon->GetActorForwardVector(), MovementVector.X);
		ControlledDragon->AddMovementInput(ControlledDragon->GetActorRightVector(), MovementVector.Y);
	}
}

void ADragonController::FireInput(const FInputActionValue& Value)
{
	ControlledDragon->Fire();
}
