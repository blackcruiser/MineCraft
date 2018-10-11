// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySystem/Info/NormalItemInfo.h"
#include "BaseItem.generated.h"

class AMineCharacter;

/**
 * 
 */
UCLASS()
class MINECRAFT_API UBaseItem : public UObject
{
	GENERATED_BODY()

public:
	UBaseItem();
	~UBaseItem();

	virtual void Use(AMineCharacter *character);

	FNormalItemInfo* GetInfo();

private:
	FNormalItemInfo* _info;
};
