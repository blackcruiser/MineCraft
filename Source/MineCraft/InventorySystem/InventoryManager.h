// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InventorySystem/Info/InventorySlotInfo.h"
#include "InventorySystem/Info/NormalItemInfo.h"

#include "InventoryManager.generated.h"

/**
 * 
 */
UCLASS()
class MINECRAFT_API UInventoryManager : public UObject
{
	GENERATED_BODY()

public:
	UInventoryManager();
	~UInventoryManager();

	bool IsSlotEmpty(int index);

	void AddItem(const FNormalItemInfo& info, int count);

	const TArray<FInventorySlotInfo>& GetInventoryArray();

private:
	TArray<FInventorySlotInfo> _slotInfoArray;

	int _slotVolume;
};
