#include "Widgets/HUD/Inv_HudWidget.h"
#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "InventoryManagement/Utilits/Inv_InventoryStatics.h"
#include "Widgets/HUD/Inv_InfoMessage.h"

void UInv_HudWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UInv_InventoryComponent* IC = UInv_InventoryStatics::GetInventoryComponent(GetOwningPlayer());
	if(!IsValid(IC)) return;

	IC->OnNoRoom.AddDynamic(this, &UInv_HudWidget::OnNoRoom);
}

void UInv_HudWidget::OnNoRoom()
{
	if (!IsValid(InfoMessage)) return;

	InfoMessage->SetMessageBlock(FText::FromString("No Room On Inventory"));
}
