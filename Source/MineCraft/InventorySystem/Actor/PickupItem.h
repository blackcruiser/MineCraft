// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Blueprint/UserWidget.h"

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
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnPickup();

	const FNormalItemInfo& getItemInfo() const;
	const int getItemCount() const;

protected:
	virtual void ShowNameBoard();
	virtual void HideNameBoard();

public:
	UPROPERTY(BlueprintReadOnly)
	USphereComponent* sphereCollider;

private:
	UUserWidget* _nameBoard;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNormalItemInfo _itemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int _count;

};
