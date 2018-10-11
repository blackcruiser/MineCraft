// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "PotionItem.generated.h"

/**
 * 
 */
UCLASS()
class MINECRAFT_API UPotionItem : public UBaseItem
{
	GENERATED_BODY()
	
public:
	virtual void Use(AMineCharacter *character);
	
private:
	int _health;
};
