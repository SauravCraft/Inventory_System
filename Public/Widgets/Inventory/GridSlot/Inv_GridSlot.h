// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_GridSlot.generated.h"

/**
 * 
 */
class UImage;
UCLASS()
class INVENTORYSYSTEM_API UInv_GridSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetTileIndex(int32 NewIndex) { TileIndex = NewIndex; }
	void GetTileIndex(int32& OutIndex) const { OutIndex = TileIndex; }

private:
	UPROPERTY()
	int32 TileIndex;


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> GridBackground;
	
};
