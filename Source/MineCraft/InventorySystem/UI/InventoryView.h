// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "InventoryView.generated.h"

/**
 * 
 */
UCLASS()
class MINECRAFT_API UInventoryView : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

protected:
	virtual void NativeConstruct() override;

	void UpdateInventory();
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UGridPanel* SlotContainer;
};
