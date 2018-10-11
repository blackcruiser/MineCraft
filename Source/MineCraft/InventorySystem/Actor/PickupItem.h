// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include <Runtime/UMG/Public/Blueprint/UserWidget.h>

#include "InventorySystem/Info/NormalItemInfo.h"

#include "PickupItem.generated.h"

UCLASS()
class MINECRAFT_API APickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	virtual void ShowNameBoard();
	virtual void HideNameBoard();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNormalItemInfo _itemInfo;

private:
	UUserWidget* _nameBoard;
};
