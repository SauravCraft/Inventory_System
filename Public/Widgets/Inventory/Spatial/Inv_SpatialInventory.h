
#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/InventoryBase/Inv_InventoryBase.h"
#include "Inv_SpatialInventory.generated.h"


class UInv_InventoryGrid;
class UWidgetSwitcher;
class UButton;

UCLASS()
class INVENTORYSYSTEM_API UInv_SpatialInventory : public UInv_InventoryBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> InventorySwitcher;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> EquippableGrid;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> ConsumableGrid;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> CraftableGrid;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> EquippableButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ConsumableButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CraftableButton;


	UFUNCTION()
	void ShowEquippableGrid();

	UFUNCTION()
	void ShowConsumableGrid();

	UFUNCTION()
	void ShowCraftableGrid();


	void DisableButton(UButton* Button);
	void SetActiveGrid(UInv_InventoryGrid* Grid , UButton* Button);


};
