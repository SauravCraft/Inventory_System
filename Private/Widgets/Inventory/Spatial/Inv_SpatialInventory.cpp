

#include "Widgets/Inventory/Spatial/Inv_SpatialInventory.h"
#include "Widgets/Inventory/Spatial/Inv_InventoryGrid.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void UInv_SpatialInventory::NativeOnInitialized()
{
	EquippableButton->OnClicked.AddDynamic(this, &UInv_SpatialInventory::ShowEquippableGrid);
	ConsumableButton->OnClicked.AddDynamic(this, &UInv_SpatialInventory::ShowConsumableGrid);
	CraftableButton->OnClicked.AddDynamic(this, &UInv_SpatialInventory::ShowCraftableGrid);

	ShowConsumableGrid();
}

void UInv_SpatialInventory::ShowEquippableGrid()
{
	SetActiveGrid(EquippableGrid, EquippableButton);
}

void UInv_SpatialInventory::ShowConsumableGrid()
{
	SetActiveGrid(ConsumableGrid, ConsumableButton);
}

void UInv_SpatialInventory::ShowCraftableGrid()
{
	SetActiveGrid(CraftableGrid, CraftableButton);
}

void UInv_SpatialInventory::DisableButton(UButton* Button)
{
	EquippableButton->SetIsEnabled(true);
	ConsumableButton->SetIsEnabled(true);
	CraftableButton->SetIsEnabled(true);
	Button->SetIsEnabled(false);
}

void UInv_SpatialInventory::SetActiveGrid(UInv_InventoryGrid* Grid, UButton* Button)
{
	DisableButton(Button);
	InventorySwitcher->SetActiveWidget(Grid);
}
