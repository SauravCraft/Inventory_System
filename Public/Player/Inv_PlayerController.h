// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UInv_HudWidget;

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

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> InventoryAction;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Interact();

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_HudWidget> HudWidgetClass;

	UPROPERTY()
	TObjectPtr<UInv_HudWidget> HudWidgetInstance;

	UFUNCTION()
	void CreateHudWidget();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InventoryToggle();


};
