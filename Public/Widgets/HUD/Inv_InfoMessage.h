// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_InfoMessage.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_InfoMessage : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ShowInfoMessage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void HideInfoMessage();

	void SetMessageBlock(FText& Message);
	
private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MessageBlock;

	FTimerHandle MessageTimer;
	bool bIsMessageActive{ false };

	UPROPERTY(EditAnywhere, Category = "Inventory")
	float MessageTime{ 3.f };

};
