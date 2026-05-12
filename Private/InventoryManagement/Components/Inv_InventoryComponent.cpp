#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "Widgets/Inventory/InventoryBase/Inv_InventoryBase.h"

UInv_InventoryComponent::UInv_InventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInv_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	ConstructInventory();
	
}

void UInv_InventoryComponent::ConstructInventory()
{
	OwningController = Cast<APlayerController>(GetOwner());

	if (!OwningController->IsLocalController()) return;

	if (InventoryWidgetClass)
	{
		InventoryWidget = CreateWidget<UInv_InventoryBase>(OwningController.Get(), InventoryWidgetClass);
		if (InventoryWidget)
		{
			InventoryWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Inventory Widget could not be created! Check if the InventoryWidgetClass is set correctly."));
		}
	}
	CloseInventory();
}

void UInv_InventoryComponent::ToggleInventory()
{
	if(bToogleInventory)
	{
		CloseInventory();
	}
	else
	{
		OpenInventory();
	}
}

void UInv_InventoryComponent::CloseInventory()
{
	if (IsValid(OwningController) && IsValid(InventoryWidget))
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
		bToogleInventory = false;

		FInputModeGameOnly InputMode;
		OwningController->SetInputMode(InputMode);
		OwningController->SetShowMouseCursor(false);
	}


}

void UInv_InventoryComponent::OpenInventory()
{
	if (IsValid(OwningController) && IsValid(InventoryWidget))
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		bToogleInventory = true;

		FInputModeGameAndUI InputMode;
		OwningController->SetInputMode(InputMode);
		OwningController->SetShowMouseCursor(true);
	}


}


