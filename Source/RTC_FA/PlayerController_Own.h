// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "PlayerController_Own.generated.h"

class UEnhancedInputComponent;
class ACharacter_Own;

/**
 *
 */
UCLASS(Abstract)
class APlayerController_OwnBase : public APlayerController
{
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> ActionMove = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> ActionLook = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> ActionJump = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> ActionAttack = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContent = nullptr;

protected:
	virtual void OnPossess(APawn *aPawn) override;
	virtual void OnUnPossess() override;

	void Move(const FInputActionValue &InputActionValue);
	void Look(const FInputActionValue &InputActionValue);
	void Jump();
	void Attack();

private:
	UPROPERTY()
	UEnhancedInputComponent *EnhancedInputComponent = nullptr;

	UPROPERTY()
	ACharacter_Own *PlayerCharacter = nullptr;

	GENERATED_BODY()
};
