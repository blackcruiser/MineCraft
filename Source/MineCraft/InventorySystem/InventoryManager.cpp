// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryManager.h"

UInventoryManager::UInventoryManager()
{
	_slotInfoArray.Init(FInventorySlotInfo(), _slotVolume);
}

UInventoryManager::~UInventoryManager()
{
}

bool UInventoryManager::IsSlotEmpty(int index)
{
	return false;
}

void UInventoryManager::AddItem(const FNormalItemInfo& info, int count)
{
	for (FInventorySlotInfo& info : _slotInfoArray)
	{
		if (info.count == 0)
		{
			info.count = count;
			info.itemClass = info.itemClass;

			break;
		}
	}
}

const TArray<FInventorySlotInfo>& UInventoryManager::GetInventoryArray()
{
	return _slotInfoArray;
}