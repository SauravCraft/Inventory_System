// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/Inv_InfoMessage.h"
#include "Components/TextBlock.h"

void UInv_InfoMessage::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MessageBlock->SetText(FText::GetEmpty());
}

void UInv_InfoMessage::SetMessageBlock(const FText& Message)
{
	MessageBlock->SetText(Message);
	if (!bIsMessageActive)
	{
		MessageShow();
	}
	bIsMessageActive = true;
	GetWorld()->GetTimerManager().SetTimer(MessageTimer, [this]()
		{
			MessageHide(); 
			bIsMessageActive = true;

		}, MessageLifeTime, false);
}
