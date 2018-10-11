// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySlot.h"
#include "InventorySystem/Item/BaseItem.h"


void UInventorySlot::SetListItemObjectInternal(UObject* InObject)
{
	UBaseItem* item = Cast<UBaseItem>(InObject);
	if (nullptr == item)
		return;

/*	if (_itemName)
		_itemName->SetText(item->GetName());

	if (_itemImage)
		_itemImage->SetBrushFromTexture(nullptr)*/;
}

