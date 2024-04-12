// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardOne.generated.h"

UCLASS()
class FINAL3DUNREAL_API ABoardOne : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoardOne();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};