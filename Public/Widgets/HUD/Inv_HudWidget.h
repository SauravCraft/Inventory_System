// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HudWidget.generated.h"

class UInv_InfoMessage;
/**
 * 
 */

UCLASS()
class INVENTORYSYSTEM_API UInv_HudWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InfoMessage> InfoMessage;

	UFUNCTION()
	void OnNoRoom();
	
};
