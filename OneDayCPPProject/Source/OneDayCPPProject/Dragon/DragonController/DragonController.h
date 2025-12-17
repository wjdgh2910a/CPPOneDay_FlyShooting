// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DragonController.generated.h"

/**
 * 
 */
UCLASS()
class ONEDAYCPPPROJECT_API ADragonController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> FireAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputMappingContext> MappingContext;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ADragon> ControlledDragon;
public:
	ADragonController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* aPawn) override;
	UFUNCTION()
	void MoveInput(const struct FInputActionValue& Value);
	UFUNCTION()
	void FireInput(const struct FInputActionValue& Value);
};
