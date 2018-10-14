// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryView.h"
#include "Components/UniformGridSlot.h"
#include "MinePlayerController.h"
#include "InventorySystem/InventoryManager.h"
#include "InventorySystem/UI/InventorySlot.h"


bool UInventoryView::Initialize()
{
	AMinePlayerController *playerController = Cast<AMinePlayerController>(GetWorld()->GetFirstPlayerController());
	if (playerController)
		_inventoryManager = playerController->GetInventoryManager();

	return Super::Initialize();
}


void UInventoryView::NativeConstruct()
{
	Super::NativeConstruct();

	//Initialize all slots
	if (_inventoryManager)
	{
		FSoftClassPath BP_InventorySlotPath(TEXT("/Game/InventorySystem/UI/W_InventorySlot.W_InventorySlot_C"));
		UClass* BP_InventorySlotClass = BP_InventorySlotPath.TryLoadClass<UUserWidget>();
		int volume = _inventoryManager->GetSlotVolume();

		slotContainer->ClearChildren();
		for (int i = 0; i < volume; i++)
		{
			UUserWidget* slot = CreateWidget<UUserWidget>(this, BP_InventorySlotClass);
			UUniformGridSlot* gridSlot = slotContainer->AddChildToUniformGrid(slot);
			gridSlot->SetRow(i / 4);
			gridSlot->SetColumn(i % 4);
		}
	}

	if (_inventoryManager)
		_refreshSlotViewAtIndexHandle = _inventoryManager->inventorySlotChangeDelegate.AddUObject(this, &UInventoryView::RefreshSlotViewAtIndex);


	RefreshAllSlotsView();
}

void UInventoryView::NativeDestruct()
{
	if (_inventoryManager)
		_inventoryManager->inventorySlotChangeDelegate.Remove(_refreshSlotViewAtIndexHandle);

	_inventoryManager = nullptr;

	Super::NativeDestruct();
}

void UInventoryView::RefreshAllSlotsView()
{
	if (_inventoryManager == nullptr)
		return;




}

void UInventoryView::RefreshSlotViewAtIndex(int index)
{
	if (_inventoryManager == nullptr)
		return;

	const FInventorySlotInfo& slotInfo = _inventoryManager->GetInventoryInfoAtIndex(index);
	UInventorySlot* slot = Cast<UInventorySlot>(slotContainer->GetChildAt(index));
	if (slot)
	{
		slot->itemName->SetText(slotInfo.itemInfo.name);
	}
}