// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class MINECRAFT_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void SetListItemObjectInternal(UObject* InObject);


public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* itemName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* itemImage;
};
