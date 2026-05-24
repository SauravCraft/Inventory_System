#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"

class UInv_InventoryBase;
class UInv_InventoryItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UInv_InventoryItem*, Item);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ,Blueprintable)
class INVENTORYSYSTEM_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInv_InventoryComponent();

protected:
	virtual void BeginPlay() override;

private:
	void ConstructInventory();

	UPROPERTY()
	TObjectPtr<UInv_InventoryBase> InventoryWidget;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_InventoryBase> InventoryWidgetClass;

	TObjectPtr<APlayerController> OwningController;

public:

	bool bToogleInventory = false;

	void ToggleInventory();
	void CloseInventory();
	void OpenInventory();

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;


};
