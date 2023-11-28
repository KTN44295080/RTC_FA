// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerController_Own.h"
#include "Character_Own.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void APlayerController_OwnBase::OnPossess(APawn *aPawn)
{
    Super::OnPossess(aPawn);

    PlayerCharacter = Cast<ACharacter_Own>(aPawn);
    PlayerCharacter->bUseControllerRotationPitch = false;
    PlayerCharacter->bUseControllerRotationYaw = false;
    PlayerCharacter->bUseControllerRotationRoll = false;

    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

    UEnhancedInputLocalPlayerSubsystem *InputSubsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMappingContent, 0);

    if (ActionMove)
    {
        EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this,
                                           &APlayerController_OwnBase::Move);
    }

    if (ActionLook)
    {
        EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this,
                                           &APlayerController_OwnBase::Look);
    }

    if (ActionJump)
    {
        EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Started, this,
                                           &APlayerController_OwnBase::Jump);
    }

    if (ActionAttack)
    {
        EnhancedInputComponent->BindAction(ActionAttack, ETriggerEvent::Started, this,
                                           &APlayerController_OwnBase::Attack);
    }
}

void APlayerController_OwnBase::OnUnPossess()
{
    EnhancedInputComponent->ClearActionBindings();
    Super::OnUnPossess();
}

void APlayerController_OwnBase::Move(const FInputActionValue &InputValue)
{
    FVector2D movementVector = InputValue.Get<FVector2D>();

    if (PlayerCharacter)
    {
        const FRotator rot = PlayerCharacter->GetControlRotation();
        const FRotator yawRotation(0, rot.Yaw, 0);

        const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
        const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

        PlayerCharacter->AddMovementInput(forwardDirection, movementVector.Y);
        PlayerCharacter->AddMovementInput(rightDirection, movementVector.X);
    }
}

void APlayerController_OwnBase::Look(const FInputActionValue &InputValue)
{
    FVector2D lookAxisVector = InputValue.Get<FVector2D>();

    if (PlayerCharacter)
    {
        PlayerCharacter->AddControllerYawInput(lookAxisVector.X);
        PlayerCharacter->AddControllerPitchInput(lookAxisVector.Y);
    }
}

void APlayerController_OwnBase::Jump()
{
    if (PlayerCharacter)
    {
        PlayerCharacter->UnCrouch();
        PlayerCharacter->Jump();
    }
}

void APlayerController_OwnBase::Attack()
{
    if (PlayerCharacter)
    {
        // PlayerCharacter->Attack();
    }
}