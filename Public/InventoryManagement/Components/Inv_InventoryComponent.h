#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "Inv_InventoryComponent.generated.h"


class UInv_ItemComponent;
class UInv_InventoryBase;
class UInv_InventoryItem;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UInv_InventoryItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNoRoomInventory);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ,Blueprintable)
class INVENTORYSYSTEM_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

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

	UInv_InventoryComponent();

	bool bToogleInventory = false;

	void ToggleInventory();
	void CloseInventory();
	void OpenInventory();

	void TryAddItem(UInv_ItemComponent* ItemComponent);

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;
	FOnNoRoomInventory OnNoRoom;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Inventory")
	void TryToAddItem(UInv_ItemComponent* ItemComponent);


};
