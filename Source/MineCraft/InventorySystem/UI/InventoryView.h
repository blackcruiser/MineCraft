// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "InventoryView.generated.h"

class UInventoryManager;
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
	virtual void NativeDestruct() override;

	void RefreshAllSlotsView();
	void RefreshSlotViewAtIndex(int index);
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* slotContainer;

private:
	UInventoryManager* _inventoryManager;
	FDelegateHandle _refreshSlotViewAtIndexHandle;
};
