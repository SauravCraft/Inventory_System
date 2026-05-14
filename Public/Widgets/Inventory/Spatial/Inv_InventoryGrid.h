// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"

#include "Inv_InventoryGrid.generated.h"

/**
 * 
 */

class UInv_GridSlot;
class UCanvasPanel;
class UImage;

UCLASS()
class INVENTORYSYSTEM_API UInv_InventoryGrid : public UUserWidget
{
	GENERATED_BODY()
private:
	virtual void NativeOnInitialized() override;


public:
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = ( allowPrivateAccess = "true" ) , Category = "Inventory")
	EInv_ItemCategory ItemCategory;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> GridCanvas;

	UPROPERTY()
	TArray<TObjectPtr<UInv_GridSlot>> GridSlots;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_GridSlot> GridSlotClass;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 GridColumns;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 GridRows;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float TileSize;

	UFUNCTION()
	void ConstructGrid();

};
