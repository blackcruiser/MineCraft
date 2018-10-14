// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NormalItemInfo.h"
#include "InventorySlotInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventorySlotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FNormalItemInfo itemInfo;

	UPROPERTY(EditAnywhere)
	int count = 0;
};
