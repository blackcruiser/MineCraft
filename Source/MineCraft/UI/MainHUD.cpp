// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHud.h"
#include "Blueprint/DragDropOperation.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

bool UMainHUD::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (InOperation && InOperation->DefaultDragVisual)
	{
		UCanvasPanelSlot* slot = canvasPanel->AddChildToCanvas(InOperation->DefaultDragVisual);
		if (slot)
		{
			FVector2D pos = InGeometry.AbsoluteToLocal(InDragDropEvent.GetLastScreenSpacePosition());

			slot->SetPosition(pos);
			slot->SetAutoSize(true);
		}

		return true;
	}

	return false;
}


