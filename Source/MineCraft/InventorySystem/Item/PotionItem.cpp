// Fill out your copyright notice in the Description page of Project Settings.

#include "PotionItem.h"
#include "MineCharacter.h"
#include "MinePlayerController.h"


void UPotionItem::Use(AMineCharacter* character)
{
	if (nullptr == character)
		return;

	AMinePlayerController *controller = Cast<AMinePlayerController>(character->GetController());
	if (nullptr == controller)
		return;

	controller->UpdateHealth(_health);
}

