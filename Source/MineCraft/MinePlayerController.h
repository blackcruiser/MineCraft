// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventorySystem/InventoryManager.h"

#include "MinePlayerController.generated.h"

class UInventoryView;
/**
 * 
 */
UCLASS()
class MINECRAFT_API AMinePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMinePlayerController();
	~AMinePlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	virtual void PlayerTick(float DeltaTime) override;

	UInventoryManager* GetInventoryManager() const;

	//Status
	void UpdateHealth(int value);

	//Interaction
	void OnToggleInventoryShow();
	void OnPickupItem();
	
private:
	UInventoryManager* _inventoryManager;
	
	UUserWidget* _mainHUD;
	UInventoryView* _inventoryView;

	int _health, _maxHealth;
	int _mana, _maxMana;
};
