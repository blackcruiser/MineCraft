// Fill out your copyright notice in the Description page of Project Settings.

#include "MinePlayerController.h"
#include "Blueprint/UserWidget.h"

#include "MineCharacter.h"
#include "InventorySystem/Actor/PickupItem.h"
#include "InventorySystem/UI/InventoryView.h"

#include <algorithm>

AMinePlayerController::AMinePlayerController()
{
	_inventoryManager = NewObject<UInventoryManager>();
}

 AMinePlayerController::~AMinePlayerController()
 {}


void AMinePlayerController::BeginPlay()
{
	Super::BeginPlay();

	FSoftClassPath W_MainHUDPath(TEXT("/Game/UI/W_MainHUD.W_MainHUD_C"));
	if (UClass* W_MainHUDClass = W_MainHUDPath.TryLoadClass<UUserWidget>())
	{
		_mainHUD = CreateWidget<UUserWidget>(this, W_MainHUDClass);
		if (_mainHUD)
		{
			_mainHUD->AddToViewport();
			_inventoryView = Cast<UInventoryView>(_mainHUD->GetWidgetFromName(TEXT("inventoryView")));
		}
	}
}

void AMinePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindKey(EKeys::I, IE_Pressed, this, &AMinePlayerController::OnToggleInventoryShow);
	InputComponent->BindKey(EKeys::E, IE_Pressed, this, &AMinePlayerController::OnPickupItem);
}

void AMinePlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AMinePlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
}

UInventoryManager* AMinePlayerController::GetInventoryManager() const
{
	return _inventoryManager;
}


void AMinePlayerController::UpdateHealth(int value)
{
	_health += value;
	_health = std::min(_health, _maxHealth);
}

void AMinePlayerController::OnToggleInventoryShow()
{
	if (nullptr == _inventoryView)
		return;

	if (_inventoryView->GetVisibility() == ESlateVisibility::Visible)
	{
		_inventoryView->SetVisibility(ESlateVisibility::Collapsed);
		bShowMouseCursor = false;
	}
	else
	{
		_inventoryView->SetVisibility(ESlateVisibility::Visible);
		bShowMouseCursor = true;
	}
}

void AMinePlayerController::OnPickupItem()
{
	AMineCharacter* character = Cast<AMineCharacter>(GetCharacter());
	if (character)
	{
		APickupItem* item = character->GetNearestPickupItem();
		if (item)
		{
			_inventoryManager->AddItem(item->getItemInfo(), item->getItemCount());
			item->OnPickup();
		}
	}
}