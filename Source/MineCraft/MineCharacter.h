// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MineCharacter.generated.h"

UCLASS()
class MINECRAFT_API AMineCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMineCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	UFUNCTION(BlueprintCallable)
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	void onMoveForwardBackward(float value);
	void onMoveLeftRight(float value);
	void onYawChange(float value);
	void onPitchChange(float value);

	void onFire();

	void OnPickup();

public:
	UFUNCTION(BlueprintCallable)
	FRotator getAimOffsets() const;

public:
};
