// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Inv_PlayerController.h"
#include "InventorySystem.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem))
	{
		for (const TObjectPtr<UInputMappingContext>& IMC : DefaultIMCs)
		{
			if (IMC)
			{
				Subsystem->AddMappingContext(IMC, 0);
			}
			else
			{
				UE_LOG(LogInventory, Warning, TEXT("Invalid Input Mapping Context in DefaultIMC array"));
			}
		}
	}
}

void AInv_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);
	if (EIC)
	{
		EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AInv_PlayerController::Interact);
	}

}

void AInv_PlayerController::Interact()
{
	UE_LOG(LogInventory, Log, TEXT("Interact action triggered"));
}

