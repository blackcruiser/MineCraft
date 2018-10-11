// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryManager.h"

UInventoryManager::UInventoryManager()
{
	_slotInfoArray.Init(FInventorySlotInfo(), _slotVolume);
}

UInventoryManager::~UInventoryManager()
{
}

const TArray<FInventorySlotInfo>& UInventoryManager::GetInventoryArray()
{
	return _slotInfoArray;
}