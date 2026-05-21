#pragma once
#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"



#include "Inv_FastArray.generated.h"
class UInv_InventoryItem;
class UInv_InventoryComponent;

USTRUCT(BlueprintType)
struct FInv_InventoryEntries : public FFastArraySerializerItem
{
	
	GENERATED_BODY()

	FInv_InventoryEntries();


private:
	friend struct FInv_InventoryFastArray;
	friend UInv_InventoryComponent;

	UPROPERTY()
	TObjectPtr<UInv_InventoryItem> Item = nullptr;


};

USTRUCT(BlueprintType)
struct FInv_InventoryFastArray : public FFastArraySerializer
{


	GENERATED_BODY()

	FInv_InventoryFastArray() : OwnerComponent(nullptr) {}
	FInv_InventoryFastArray(UActorComponent* InOwnerComponent) : OwnerComponent(InOwnerComponent) {}

	void PostReplicatedAdd( const TArrayView<int32> AddedIndex , int32 FinalSize);
	void preReplicatedRemove(const TArrayView<int32> RemovedIndex , int32 FinalSize);




	TArray<UInv_InventoryItem*> GetAllEntries() const;

	UInv_InventoryItem* AddItem(UInv_InventoryItem* Item);
	UInv_InventoryItem* AddItem(UInv_InventoryComponent* ItemComp);

	void RemoveItem(UInv_InventoryItem* Item);


	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
	{
		return FastArrayDeltaSerialize<FInv_InventoryEntries, FInv_InventoryFastArray>(Entries, DeltaParams, *this);
	}

private:

	friend UInv_InventoryComponent;

	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;

	UPROPERTY()
	TArray<FInv_InventoryEntries> Entries;
};

template<>
struct TStructOpsTypeTraits<FInv_InventoryFastArray> : public TStructOpsTypeTraitsBase2<FInv_InventoryFastArray>
{
	enum { WithNetDeltaSerializer = true };
};
