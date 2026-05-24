#include "InventoryManagement/FastArray/Inv_FastArray.h"
#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "InventoryManagement/Utilits/Inv_InventoryStatics.h"
#include "Items/Inv_InventoryItem.h"


void FInv_InventoryFastArray::PostReplicatedAdd(const TArrayView<int32> AddedIndex, int32 FinalSize)
{
	UInv_InventoryComponent* IC = Cast<UInv_InventoryComponent>(OwnerComponent);
	if (!IsValid(IC)) return;
	for (int32 Index : AddedIndex)
	{
		IC->OnItemAdded.Broadcast(Entries[Index].Item);
	}
}

void FInv_InventoryFastArray::preReplicatedRemove(const TArrayView<int32> RemovedIndex, int32 FinalSize)
{
	UInv_InventoryComponent* IC = Cast<UInv_InventoryComponent>(OwnerComponent);
	if (!IsValid(IC)) return;
	for (int32 Index : RemovedIndex)
	{
		IC->OnItemRemoved.Broadcast(Entries[Index].Item);
	}

}

TArray<UInv_InventoryItem*> FInv_InventoryFastArray::GetAllEntries() const
{
	TArray<UInv_InventoryItem*> Results;
	Results.Reserve(Entries.Num());
	for (const auto& Entry : Entries)
	{
		if (!IsValid(Entry.Item)) continue;
		Results.Add(Entry.Item);
	}

	return Results;
}

UInv_InventoryItem* FInv_InventoryFastArray::AddItem(UInv_InventoryItem* Item)
{
	check(OwnerComponent);
	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority());

	FInv_InventoryEntries& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = Item;
	MarkItemDirty(NewEntry);

	return Item;
}

UInv_InventoryItem* FInv_InventoryFastArray::AddItem(UInv_InventoryComponent* ItemComp)
{
	return nullptr;

	// TODO: After Full Construction of Inventory Component


}

void FInv_InventoryFastArray::RemoveItem(UInv_InventoryItem* Item)
{
	
	for (auto It = Entries.CreateIterator() ; It ; ++It)
	{
		FInv_InventoryEntries& Entry = *It;
		if (Entry.Item == Item)
		{
			It.RemoveCurrent();
			MarkArrayDirty();
		}
	}
}

FInv_InventoryEntries::FInv_InventoryEntries()
{
}
