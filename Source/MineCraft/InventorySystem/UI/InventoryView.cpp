// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryView.h"
#include "MinePlayerController.h"
#include "InventorySystem/InventoryManager.h"


bool UInventoryView::Initialize()
{
	return Super::Initialize();
}


void UInventoryView::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateInventory();
}


void UInventoryView::UpdateInventory()
{
	AMinePlayerController* playerController = Cast<AMinePlayerController>(GetWorld()->GetFirstPlayerController());
	if (nullptr == playerController)
		return;

	UInventoryManager* manager = playerController->GetInventoryManager();
	const TArray<FInventorySlotInfo>& inventoryArray = manager->GetInventoryArray();
	FSoftClassPath BP_InventorySlotPath(TEXT("/Game/InventorySystem/UI/W_InventorySlot.W_InventorySlot_C"));
	UClass* BP_InventorySlotClass = BP_InventorySlotPath.TryLoadClass<UUserWidget>();

	SlotContainer->ClearChildren();
	for (const FInventorySlotInfo& info : inventoryArray)
	{
		UUserWidget* slot = CreateWidget<UUserWidget>(this, BP_InventorySlotClass);
		SlotContainer->AddChildToGrid(slot);
	}
}