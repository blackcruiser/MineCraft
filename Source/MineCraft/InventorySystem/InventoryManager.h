// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InventorySystem/Info/InventorySlotInfo.h"
#include "InventorySystem/Info/NormalItemInfo.h"

#include "InventoryManager.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(InventorySlotChangeDelegate, int)
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

	void AddItem(const FNormalItemInfo& info, int count);

	int GetSlotVolume() const;

	bool IsSlotEmpty(int index);

	const TArray<FInventorySlotInfo>& GetInventoryInfoArray();
	const FInventorySlotInfo& GetInventoryInfoAtIndex(int index) const;


public:
	InventorySlotChangeDelegate inventorySlotChangeDelegate;

private:
	TArray<FInventorySlotInfo> _slotInfoArray;

	int _slotVolume;
};
