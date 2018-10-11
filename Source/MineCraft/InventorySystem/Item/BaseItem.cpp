// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseItem.h"


UBaseItem::UBaseItem()
{

}

UBaseItem::~UBaseItem()
{

}

void UBaseItem::Use(AMineCharacter *character)
{

}

FNormalItemInfo* UBaseItem::GetInfo()
{
	return _info;
}