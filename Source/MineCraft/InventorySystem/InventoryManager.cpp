// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryManager.h"

UInventoryManager::UInventoryManager() :
	_slotVolume(100)
{
	_slotInfoArray.Init(FInventorySlotInfo(), _slotVolume);
}

UInventoryManager::~UInventoryManager()
{
}


void UInventoryManager::AddItem(const FNormalItemInfo& info, int count)
{
	for (int i = 0; i < _slotInfoArray.Num(); i++)
	{
		FInventorySlotInfo& slotInfo = _slotInfoArray[i];

		if (slotInfo.count == 0)
		{
			slotInfo.itemInfo = info;
			slotInfo.count = count;

			inventorySlotChangeDelegate.Broadcast(i);
			break;
		}
	}
}

int UInventoryManager::GetSlotVolume() const
{
	return _slotVolume;
}

bool UInventoryManager::IsSlotEmpty(int index)
{
	return false;
}

const TArray<FInventorySlotInfo>& UInventoryManager::GetInventoryInfoArray()
{
	return _slotInfoArray;
}

const FInventorySlotInfo& UInventoryManager::GetInventoryInfoAtIndex(int index) const
{
	return _slotInfoArray[index];
}