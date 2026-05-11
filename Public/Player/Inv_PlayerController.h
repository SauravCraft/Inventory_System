// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */


UCLASS()
class INVENTORYSYSTEM_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()



protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> InteractAction;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Interact();

};
