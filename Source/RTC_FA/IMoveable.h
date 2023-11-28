// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IMoveable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UIMoveable : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class RTC_FA_API IIMoveable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interface")
	void Move(FVector2D input);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interface")
	void Rotate(FVector2D input);
};
