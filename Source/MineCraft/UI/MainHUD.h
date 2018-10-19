// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHud.generated.h"

class UCanvasPanel;

/**
 * 
 */
UCLASS()
class MINECRAFT_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation);
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* canvasPanel;
};
