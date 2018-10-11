// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMesh.h"

#include "NormalItemInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNormalItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FText name;

	UPROPERTY(EditAnywhere)
	UStaticMesh* mesh;
};
