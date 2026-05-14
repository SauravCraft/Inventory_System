// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Inv_InventoryGrid.h"
#include "Widgets/Inventory/GridSlot/Inv_GridSlot.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include <Widgets/Utils/Inv_WidgetUtils.h>
#include <Blueprint/WidgetLayoutLibrary.h>

void UInv_InventoryGrid::NativeOnInitialized()
{
	ConstructGrid();
}

void UInv_InventoryGrid::ConstructGrid()
{
	GridSlots.Reserve(GridRows * GridColumns);

	for (int32 i = 0; i < GridRows; ++i)
	{
		for (int32 j = 0 ; j < GridColumns ; ++j)
		{
			
			UInv_GridSlot* NewSlot = CreateWidget<UInv_GridSlot>(this, GridSlotClass);
			GridCanvas->AddChild(NewSlot);

			FIntPoint TilePosition(j, i);
			NewSlot->SetTileIndex(UInv_WidgetUtils::GetGridPositionByIndex(TilePosition, GridColumns));


			UCanvasPanelSlot* GridCPS = UWidgetLayoutLibrary::SlotAsCanvasSlot(NewSlot);
			GridCPS->SetSize(FVector2D(TileSize));
			GridCPS->SetPosition(TilePosition * TileSize);

			GridSlots.Add(NewSlot);

		}
	}
}
