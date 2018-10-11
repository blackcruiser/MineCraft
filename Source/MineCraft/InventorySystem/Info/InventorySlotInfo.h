// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	UClass* itemClass;

	UPROPERTY(EditAnywhere)
	int count = 0;
};
