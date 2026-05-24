// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Inv_PlayerController.h"
#include "InventorySystem.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Items/Components/Inv_ItemComponent.h"
#include <Kismet/GameplayStatics.h>
#include "Widgets/HUD/Inv_HudWidget.h"
#include "InventoryManagement/Utilits/Inv_InventoryStatics.h"
#include <InventoryManagement/Components/Inv_InventoryComponent.h>


void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	CreateHudWidget();
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
		EIC->BindAction(InventoryAction, ETriggerEvent::Started, this, &AInv_PlayerController::InventoryToggle);
	}

}

void AInv_PlayerController::Interact()
{
	if (!GEngine || !GEngine->GameViewport) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);

	FVector2D CrosshairPosition = ViewportSize * 0.5f;
	FVector WorldLocation, WorldDirection;

	if (!UGameplayStatics::DeprojectScreenToWorld(this, CrosshairPosition, WorldLocation, WorldDirection)) return;

	FHitResult HitResult;

	bool bHit = GetWorld()->SweepSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 1000.0f, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(50.0f));
	if(!bHit) return;

	AActor* HitActor = HitResult.GetActor();
	if (!HitActor) return;
	UE_LOG(LogInventory, Log, TEXT("Hit Actor: %s"), *HitActor->GetName());
	HitActor->Destroy();

	UInv_InventoryComponent* IC = FindComponentByClass<UInv_InventoryComponent>();
	UInv_ItemComponent* ItemComp = HitActor->FindComponentByClass<UInv_ItemComponent>();
	IC->TryToAddItem(ItemComp);
}

void AInv_PlayerController::CreateHudWidget()
{
	if (IsLocalPlayerController() && HudWidgetClass)
	{
		HudWidgetInstance = CreateWidget<UInv_HudWidget>(this, HudWidgetClass);
		if (HudWidgetInstance)
		{
			HudWidgetInstance->AddToViewport();
		}
		else
		{
			UE_LOG(LogInventory, Warning, TEXT("Failed to create HUD widget instance"));
		}
	}

}

void AInv_PlayerController::InventoryToggle()
{
	FindComponentByClass<UInv_InventoryComponent>()->ToggleInventory();

}

